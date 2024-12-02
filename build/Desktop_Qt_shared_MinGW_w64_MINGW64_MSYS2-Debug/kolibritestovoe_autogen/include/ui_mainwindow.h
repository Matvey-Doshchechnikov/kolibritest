/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *outputFileActionComboBox;
    QCheckBox *timerModeCheckBox;
    QSpinBox *pollingIntervalSpinBox;
    QLabel *label_2;
    QLabel *statusLabel;
    QLineEdit *xorKeyLineEdit;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *filePathLineEdit;
    QPushButton *browseFileButton;
    QLabel *label_4;
    QLineEdit *savePathLineEdit;
    QPushButton *savePathButton;
    QCheckBox *deleteFilesCheckBox;
    QPushButton *processFilesButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        outputFileActionComboBox = new QComboBox(centralwidget);
        outputFileActionComboBox->setObjectName("outputFileActionComboBox");
        outputFileActionComboBox->setGeometry(QRect(220, 50, 151, 24));
        timerModeCheckBox = new QCheckBox(centralwidget);
        timerModeCheckBox->setObjectName("timerModeCheckBox");
        timerModeCheckBox->setGeometry(QRect(410, 20, 161, 22));
        pollingIntervalSpinBox = new QSpinBox(centralwidget);
        pollingIntervalSpinBox->setObjectName("pollingIntervalSpinBox");
        pollingIntervalSpinBox->setGeometry(QRect(410, 70, 42, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 50, 131, 16));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(20, 280, 161, 31));
        xorKeyLineEdit = new QLineEdit(centralwidget);
        xorKeyLineEdit->setObjectName("xorKeyLineEdit");
        xorKeyLineEdit->setGeometry(QRect(210, 150, 261, 24));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 120, 291, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 20, 131, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 173, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        filePathLineEdit = new QLineEdit(widget);
        filePathLineEdit->setObjectName("filePathLineEdit");

        verticalLayout->addWidget(filePathLineEdit);

        browseFileButton = new QPushButton(widget);
        browseFileButton->setObjectName("browseFileButton");

        verticalLayout->addWidget(browseFileButton);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        savePathLineEdit = new QLineEdit(widget);
        savePathLineEdit->setObjectName("savePathLineEdit");

        verticalLayout->addWidget(savePathLineEdit);

        savePathButton = new QPushButton(widget);
        savePathButton->setObjectName("savePathButton");

        verticalLayout->addWidget(savePathButton);

        deleteFilesCheckBox = new QCheckBox(widget);
        deleteFilesCheckBox->setObjectName("deleteFilesCheckBox");

        verticalLayout->addWidget(deleteFilesCheckBox);

        processFilesButton = new QPushButton(widget);
        processFilesButton->setObjectName("processFilesButton");

        verticalLayout->addWidget(processFilesButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        timerModeCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \320\277\320\276 \321\202\320\260\320\271\320\274\320\265\321\200\321\203?", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 8 \320\261\320\260\320\271\321\202 \320\264\320\273\321\217 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
        browseFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", nullptr));
        savePathButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\203\321\202\321\214", nullptr));
        deleteFilesCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273 ?", nullptr));
        processFilesButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
