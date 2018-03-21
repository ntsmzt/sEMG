/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser_log;
    QComboBox *comboBox_baudRate;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_send;
    QPushButton *pushButton_send;
    QPushButton *pushButton_open;
    QPushButton *pushButton_close;
    QPushButton *pushButton_clearLog;
    QCustomPlot *customPlot1;
    QCustomPlot *customPlot_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_channel1;
    QLineEdit *lineEdit_channel2;
    QLabel *label_5;
    QLineEdit *lineEdit_channel3;
    QLabel *label_6;
    QLineEdit *lineEdit_channel4;
    QLabel *label_7;
    QLineEdit *lineEdit_channel5;
    QLabel *label_8;
    QLineEdit *lineEdit_channel6;
    QLabel *label_9;
    QLineEdit *lineEdit_channel7;
    QLabel *label_10;
    QLineEdit *lineEdit_channel8;
    QLabel *label_4;
    QCustomPlot *customPlot2;
    QCustomPlot *customPlot_4;
    QCustomPlot *customPlot3;
    QCustomPlot *customPlot_6;
    QCustomPlot *customPlot5;
    QCustomPlot *customPlot_12;
    QCustomPlot *customPlot6;
    QCustomPlot *customPlot_14;
    QCustomPlot *customPlot7;
    QCustomPlot *customPlot_16;
    QCustomPlot *customPlot8;
    QCustomPlot *customPlot_18;
    QCustomPlot *customPlot4;
    QCustomPlot *customPlot_10;
    QComboBox *portBox;
    QPushButton *pushButton_fresh;
    QPushButton *pushButton_squareWaveTest;
    QPushButton *pushButton_noiseTest;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_stopReadC;
    QPushButton *pushButton_beginReadC;
    QPushButton *pushButton_normalTest;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(983, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser_log = new QTextBrowser(centralWidget);
        textBrowser_log->setObjectName(QStringLiteral("textBrowser_log"));
        textBrowser_log->setGeometry(QRect(320, 10, 261, 81));
        comboBox_baudRate = new QComboBox(centralWidget);
        comboBox_baudRate->setObjectName(QStringLiteral("comboBox_baudRate"));
        comboBox_baudRate->setGeometry(QRect(110, 50, 61, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 54, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 50, 54, 12));
        lineEdit_send = new QLineEdit(centralWidget);
        lineEdit_send->setObjectName(QStringLiteral("lineEdit_send"));
        lineEdit_send->setGeometry(QRect(60, 80, 111, 20));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(180, 80, 71, 20));
        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setGeometry(QRect(180, 20, 71, 20));
        pushButton_close = new QPushButton(centralWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(180, 50, 71, 20));
        pushButton_clearLog = new QPushButton(centralWidget);
        pushButton_clearLog->setObjectName(QStringLiteral("pushButton_clearLog"));
        pushButton_clearLog->setGeometry(QRect(320, 90, 261, 16));
        customPlot1 = new QCustomPlot(centralWidget);
        customPlot1->setObjectName(QStringLiteral("customPlot1"));
        customPlot1->setGeometry(QRect(50, 120, 381, 121));
        customPlot_2 = new QCustomPlot(customPlot1);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));
        customPlot_2->setGeometry(QRect(360, 80, 381, 201));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(450, 120, 81, 204));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEdit_channel1 = new QLineEdit(formLayoutWidget);
        lineEdit_channel1->setObjectName(QStringLiteral("lineEdit_channel1"));
        lineEdit_channel1->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_channel1);

        lineEdit_channel2 = new QLineEdit(formLayoutWidget);
        lineEdit_channel2->setObjectName(QStringLiteral("lineEdit_channel2"));
        lineEdit_channel2->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_channel2);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        lineEdit_channel3 = new QLineEdit(formLayoutWidget);
        lineEdit_channel3->setObjectName(QStringLiteral("lineEdit_channel3"));
        lineEdit_channel3->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_channel3);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        lineEdit_channel4 = new QLineEdit(formLayoutWidget);
        lineEdit_channel4->setObjectName(QStringLiteral("lineEdit_channel4"));
        lineEdit_channel4->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_channel4);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        lineEdit_channel5 = new QLineEdit(formLayoutWidget);
        lineEdit_channel5->setObjectName(QStringLiteral("lineEdit_channel5"));
        lineEdit_channel5->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_channel5);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        lineEdit_channel6 = new QLineEdit(formLayoutWidget);
        lineEdit_channel6->setObjectName(QStringLiteral("lineEdit_channel6"));
        lineEdit_channel6->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_channel6);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

        lineEdit_channel7 = new QLineEdit(formLayoutWidget);
        lineEdit_channel7->setObjectName(QStringLiteral("lineEdit_channel7"));
        lineEdit_channel7->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_channel7);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_10);

        lineEdit_channel8 = new QLineEdit(formLayoutWidget);
        lineEdit_channel8->setObjectName(QStringLiteral("lineEdit_channel8"));
        lineEdit_channel8->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_channel8);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        customPlot2 = new QCustomPlot(centralWidget);
        customPlot2->setObjectName(QStringLiteral("customPlot2"));
        customPlot2->setGeometry(QRect(50, 250, 381, 131));
        customPlot_4 = new QCustomPlot(customPlot2);
        customPlot_4->setObjectName(QStringLiteral("customPlot_4"));
        customPlot_4->setGeometry(QRect(360, 80, 381, 201));
        customPlot3 = new QCustomPlot(centralWidget);
        customPlot3->setObjectName(QStringLiteral("customPlot3"));
        customPlot3->setGeometry(QRect(50, 390, 381, 121));
        customPlot_6 = new QCustomPlot(customPlot3);
        customPlot_6->setObjectName(QStringLiteral("customPlot_6"));
        customPlot_6->setGeometry(QRect(360, 80, 381, 201));
        customPlot5 = new QCustomPlot(centralWidget);
        customPlot5->setObjectName(QStringLiteral("customPlot5"));
        customPlot5->setGeometry(QRect(550, 120, 381, 121));
        customPlot_12 = new QCustomPlot(customPlot5);
        customPlot_12->setObjectName(QStringLiteral("customPlot_12"));
        customPlot_12->setGeometry(QRect(360, 80, 381, 201));
        customPlot6 = new QCustomPlot(centralWidget);
        customPlot6->setObjectName(QStringLiteral("customPlot6"));
        customPlot6->setGeometry(QRect(550, 250, 381, 131));
        customPlot_14 = new QCustomPlot(customPlot6);
        customPlot_14->setObjectName(QStringLiteral("customPlot_14"));
        customPlot_14->setGeometry(QRect(360, 80, 381, 201));
        customPlot7 = new QCustomPlot(centralWidget);
        customPlot7->setObjectName(QStringLiteral("customPlot7"));
        customPlot7->setGeometry(QRect(550, 390, 381, 121));
        customPlot_16 = new QCustomPlot(customPlot7);
        customPlot_16->setObjectName(QStringLiteral("customPlot_16"));
        customPlot_16->setGeometry(QRect(360, 80, 381, 201));
        customPlot8 = new QCustomPlot(centralWidget);
        customPlot8->setObjectName(QStringLiteral("customPlot8"));
        customPlot8->setGeometry(QRect(550, 520, 381, 121));
        customPlot_18 = new QCustomPlot(customPlot8);
        customPlot_18->setObjectName(QStringLiteral("customPlot_18"));
        customPlot_18->setGeometry(QRect(360, 80, 381, 201));
        customPlot4 = new QCustomPlot(centralWidget);
        customPlot4->setObjectName(QStringLiteral("customPlot4"));
        customPlot4->setGeometry(QRect(50, 520, 381, 121));
        customPlot_10 = new QCustomPlot(customPlot4);
        customPlot_10->setObjectName(QStringLiteral("customPlot_10"));
        customPlot_10->setGeometry(QRect(360, 80, 381, 201));
        portBox = new QComboBox(centralWidget);
        portBox->setObjectName(QStringLiteral("portBox"));
        portBox->setGeometry(QRect(110, 20, 61, 22));
        pushButton_fresh = new QPushButton(centralWidget);
        pushButton_fresh->setObjectName(QStringLiteral("pushButton_fresh"));
        pushButton_fresh->setGeometry(QRect(10, 20, 41, 23));
        pushButton_squareWaveTest = new QPushButton(centralWidget);
        pushButton_squareWaveTest->setObjectName(QStringLiteral("pushButton_squareWaveTest"));
        pushButton_squareWaveTest->setGeometry(QRect(620, 20, 75, 23));
        pushButton_noiseTest = new QPushButton(centralWidget);
        pushButton_noiseTest->setObjectName(QStringLiteral("pushButton_noiseTest"));
        pushButton_noiseTest->setGeometry(QRect(710, 20, 75, 23));
        pushButton_reset = new QPushButton(centralWidget);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(620, 60, 75, 23));
        pushButton_stopReadC = new QPushButton(centralWidget);
        pushButton_stopReadC->setObjectName(QStringLiteral("pushButton_stopReadC"));
        pushButton_stopReadC->setGeometry(QRect(800, 60, 75, 23));
        pushButton_beginReadC = new QPushButton(centralWidget);
        pushButton_beginReadC->setObjectName(QStringLiteral("pushButton_beginReadC"));
        pushButton_beginReadC->setGeometry(QRect(710, 60, 75, 23));
        pushButton_normalTest = new QPushButton(centralWidget);
        pushButton_normalTest->setObjectName(QStringLiteral("pushButton_normalTest"));
        pushButton_normalTest->setGeometry(QRect(800, 20, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 983, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        comboBox_baudRate->clear();
        comboBox_baudRate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "921600", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
        );
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        pushButton_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        pushButton_close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", 0));
        pushButton_clearLog->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Ch1:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Ch3:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Ch4:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Ch5:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Ch6:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Ch7:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Ch8:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Ch2", 0));
        pushButton_fresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        pushButton_squareWaveTest->setText(QApplication::translate("MainWindow", "Square Wave", 0));
        pushButton_noiseTest->setText(QApplication::translate("MainWindow", "Noise Test", 0));
        pushButton_reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        pushButton_stopReadC->setText(QApplication::translate("MainWindow", "Stop ReaadC", 0));
        pushButton_beginReadC->setText(QApplication::translate("MainWindow", "Begin ReadC", 0));
        pushButton_normalTest->setText(QApplication::translate("MainWindow", "Normal Test", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
