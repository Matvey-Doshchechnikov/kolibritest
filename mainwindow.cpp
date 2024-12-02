#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QByteArray>
#include <QTextStream>
#include <QIODevice>
#include <QRegularExpression>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pollingTimer(new QTimer(this))
{
    ui->setupUi(this);
    ui->outputFileActionComboBox->addItem("Перезаписать");
    ui->outputFileActionComboBox->addItem("Добавить счетчик");
    connect(pollingTimer, &QTimer::timeout, this, &MainWindow::on_timerTimeout);
    connect(ui->browseFileButton, &QPushButton::clicked, this, &MainWindow::on_browseFileButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Обработка нажатия на кнопку выбора файла
void MainWindow::on_browseFileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите входной файл"), QString(), tr("Все файлы (*.*)"));
    if (!filePath.isEmpty()) {
        ui->filePathLineEdit->setText(filePath);
    }
}

void MainWindow::on_processFilesButton_clicked()
{
    QString xorKey = ui->xorKeyLineEdit->text();
    // Проверка ключа XOR
    if (!validateXorKey(xorKey)) {
        QMessageBox::warning(this, "Ошибка", "Введите корректное 8-байтное значение для XOR в формате HEX (например, 0x123456789ABCDEF0).");
        return;
    }

    QString filePath = ui->filePathLineEdit->text().trimmed();
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите путь к входному файлу.");
        return;
    }

    QString savePath = ui->savePathLineEdit->text().trimmed();
    if (savePath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Укажите путь для сохранения");
        return;
    }

    QDir dir(savePath);
    if (!dir.exists()) {
        QMessageBox::warning(this, "Ошибка", QString("Указанная папка для сохранения не существует: %1").arg(savePath));
        return;
    }

    if (ui->timerModeCheckBox->isChecked()) {
        int interval = ui->pollingIntervalSpinBox->value();
        if (pollingTimer->isActive()) {
            QMessageBox::warning(this, tr("Ошибка"), tr("Процесс уже запущен по таймеру!"));
            return;
        }
        pollingTimer->start(interval);
        ui->statusLabel->setText("Статус: Работа по таймеру");
    } else {
        processFiles();
    }
}
// Получение XOR-ключа в виде массива байтов
QByteArray MainWindow::getXorKey()
{
    QString xorKey = ui->xorKeyLineEdit->text();
    if (!validateXorKey(xorKey)) {
        return QByteArray();
    }
    return QByteArray::fromHex(xorKey.mid(2).toUtf8());
}
// Основная функция обработки файлов

void MainWindow::processFiles()
{
    QString filePath = ui->filePathLineEdit->text().trimmed();
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Пожалуйста, укажите путь к входному файлу!"));
        return;
    }

    QFile inputFile(filePath);
    if (!inputFile.exists()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Указанный файл не существует: %1").arg(filePath));
        return;
    }

    if (!inputFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось открыть входной файл для чтения: %1").arg(filePath));
        return;
    }

    QString savePath = ui->savePathLineEdit->text().trimmed();
    QString outputFileName = QFileInfo(filePath).fileName();
    QString outputFilePath = savePath + "/" + outputFileName;
    // Обработка действия с выходным файлом (добавление счетчика, если файл существует)
    if (ui->outputFileActionComboBox->currentText() == tr("Добавить счетчик")) {
        int counter = 1;
        while (QFile::exists(outputFilePath)) {
            outputFilePath = QString("%1/%2_%3.%4")
            .arg(savePath, QFileInfo(filePath).baseName())
                .arg(counter++)
                .arg(QFileInfo(filePath).suffix());
        }
    }

    if (outputFilePath == filePath) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Путь для сохранения совпадает с исходным файлом!"));
        return;
    }

    QFile outputFile(outputFilePath);
    if (!outputFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось создать выходной файл: %1").arg(outputFilePath));
        return;
    }

    QByteArray xorKey = getXorKey();
    if (xorKey.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Укажите корректный 8-байтный XOR-ключ!"));
        return;
    }

    qint64 totalBytesRead = 0;
    qint64 totalBytesWritten = 0;

    // Чтение и XOR побайтово
    QByteArray buffer;
    while (!(buffer = inputFile.read(256)).isEmpty()) {
        totalBytesRead += buffer.size();
        for (int i = 0; i < buffer.size(); ++i) {
            buffer[i] ^= xorKey[i % xorKey.size()];
        }
        qint64 bytesWritten = outputFile.write(buffer);
        if (bytesWritten == -1) {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось записать данные в выходной файл."));
            return;
        }
        totalBytesWritten += bytesWritten;
    }

    inputFile.close();
    outputFile.close();

    QMessageBox::information(this, tr("Успех"), tr("Файл обработан и сохранён как: %1\nПрочитано байтов: %2\nЗаписано байтов: %3")
                                                    .arg(outputFilePath).arg(totalBytesRead).arg(totalBytesWritten));
}


QString MainWindow::getOutputFileName(const QString &fileName)
{
    QString outputFileName = ui->savePathLineEdit->text() + "/" + QFileInfo(fileName).fileName();
    QString action = ui->outputFileActionComboBox->currentText();

    if (QFile::exists(outputFileName) && action == "Добавить счетчик") {
        int counter = 1;
        QString baseName = QFileInfo(fileName).baseName();
        QString extension = QFileInfo(fileName).suffix();
        while (QFile::exists(outputFileName)) {
            outputFileName = ui->savePathLineEdit->text() + "/" + baseName + "_" + QString::number(counter++) + "." + extension;
        }
    }

    return outputFileName;
}
// Валидация ключа XOR
bool MainWindow::validateXorKey(const QString &key)
{
    QRegularExpression hexRegex("^0x[0-9A-Fa-f]{16}$");
    return hexRegex.match(key).hasMatch();
}

void MainWindow::on_savePathButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Выберите папку для сохранения");
    if (!directory.isEmpty()) {
        ui->savePathLineEdit->setText(directory);
    }
}

void MainWindow::on_timerTimeout()
{
    processFiles();
}
