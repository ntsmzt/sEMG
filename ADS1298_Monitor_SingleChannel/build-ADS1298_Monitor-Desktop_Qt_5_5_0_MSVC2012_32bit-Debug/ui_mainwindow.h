/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
    QCustomPlot *customPlot;
    QComboBox *portBox;
    QPushButton *pushButton_fresh;
    QPushButton *pushButton_squareWaveTest;
    QPushButton *pushButton_noiseTest;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_stopReadC;
    QPushButton *pushButton_beginReadC;
    QPushButton *pushButton_normalTest;
    QLineEdit *lineEdit_channel;
    QComboBox *comboBox_channel;
    QPushButton *ChannelAllButton;
    QPushButton *savebutton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(983, 598);
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
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(50, 120, 811, 381));
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
        lineEdit_channel = new QLineEdit(centralWidget);
        lineEdit_channel->setObjectName(QStringLiteral("lineEdit_channel"));
        lineEdit_channel->setGeometry(QRect(880, 150, 81, 20));
        lineEdit_channel->setReadOnly(true);
        comboBox_channel = new QComboBox(centralWidget);
        comboBox_channel->setObjectName(QStringLiteral("comboBox_channel"));
        comboBox_channel->setGeometry(QRect(880, 120, 81, 22));
        ChannelAllButton = new QPushButton(centralWidget);
        ChannelAllButton->setObjectName(QStringLiteral("ChannelAllButton"));
        ChannelAllButton->setGeometry(QRect(880, 180, 75, 23));
        savebutton = new QPushButton(centralWidget);
        savebutton->setObjectName(QStringLiteral("savebutton"));
        savebutton->setGeometry(QRect(890, 60, 75, 23));
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
        pushButton_fresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        pushButton_squareWaveTest->setText(QApplication::translate("MainWindow", "Square Wave", 0));
        pushButton_noiseTest->setText(QApplication::translate("MainWindow", "Noise Test", 0));
        pushButton_reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        pushButton_stopReadC->setText(QApplication::translate("MainWindow", "Stop ReaadC", 0));
        pushButton_beginReadC->setText(QApplication::translate("MainWindow", "Begin ReadC", 0));
        pushButton_normalTest->setText(QApplication::translate("MainWindow", "Normal Test", 0));
        ChannelAllButton->setText(QApplication::translate("MainWindow", "ChannelAll", 0));
        savebutton->setText(QApplication::translate("MainWindow", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
