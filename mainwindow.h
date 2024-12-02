#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_processFilesButton_clicked();
    void on_savePathButton_clicked();
    void on_timerTimeout();
    void on_browseFileButton_clicked();


private:
    Ui::MainWindow *ui;

    QTimer *pollingTimer; // Таймер для периодического опроса

    // Вспомогательные функции
    void processFiles();
    QString getSavePath();
    QString getOutputFileName(const QString &fileName);
    bool validateXorKey(const QString &key);
    quint64 parseXorKey(const QString &key);
    QByteArray getXorKey();
};

#endif // MAINWINDOW_H
