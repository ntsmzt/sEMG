/********************************************************************************
** Form generated from reading UI file 'channelallwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELALLWINDOW_H
#define UI_CHANNELALLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ChannelAllWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *customPlot1;
    QCustomPlot *customPlot2;
    QCustomPlot *customPlot4;
    QCustomPlot *customPlot6;
    QCustomPlot *customPlot3;
    QCustomPlot *customPlot5;
    QCustomPlot *customPlot7;
    QCustomPlot *customPlot8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChannelAllWindow)
    {
        if (ChannelAllWindow->objectName().isEmpty())
            ChannelAllWindow->setObjectName(QStringLiteral("ChannelAllWindow"));
        ChannelAllWindow->resize(1036, 664);
        centralwidget = new QWidget(ChannelAllWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        customPlot1 = new QCustomPlot(centralwidget);
        customPlot1->setObjectName(QStringLiteral("customPlot1"));
        customPlot1->setGeometry(QRect(70, 20, 421, 131));
        customPlot2 = new QCustomPlot(centralwidget);
        customPlot2->setObjectName(QStringLiteral("customPlot2"));
        customPlot2->setGeometry(QRect(570, 20, 421, 131));
        customPlot4 = new QCustomPlot(centralwidget);
        customPlot4->setObjectName(QStringLiteral("customPlot4"));
        customPlot4->setGeometry(QRect(570, 180, 421, 131));
        customPlot6 = new QCustomPlot(centralwidget);
        customPlot6->setObjectName(QStringLiteral("customPlot6"));
        customPlot6->setGeometry(QRect(570, 340, 421, 131));
        customPlot3 = new QCustomPlot(centralwidget);
        customPlot3->setObjectName(QStringLiteral("customPlot3"));
        customPlot3->setGeometry(QRect(70, 180, 421, 131));
        customPlot5 = new QCustomPlot(centralwidget);
        customPlot5->setObjectName(QStringLiteral("customPlot5"));
        customPlot5->setGeometry(QRect(70, 340, 421, 131));
        customPlot7 = new QCustomPlot(centralwidget);
        customPlot7->setObjectName(QStringLiteral("customPlot7"));
        customPlot7->setGeometry(QRect(70, 500, 421, 131));
        customPlot8 = new QCustomPlot(centralwidget);
        customPlot8->setObjectName(QStringLiteral("customPlot8"));
        customPlot8->setGeometry(QRect(570, 500, 421, 131));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 31, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(530, 70, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 230, 31, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(530, 230, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 390, 31, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(530, 390, 31, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 540, 31, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(530, 540, 31, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        ChannelAllWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChannelAllWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1036, 23));
        ChannelAllWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChannelAllWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChannelAllWindow->setStatusBar(statusbar);

        retranslateUi(ChannelAllWindow);

        QMetaObject::connectSlotsByName(ChannelAllWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChannelAllWindow)
    {
        ChannelAllWindow->setWindowTitle(QApplication::translate("ChannelAllWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("ChannelAllWindow", "CH1", 0));
        label_3->setText(QApplication::translate("ChannelAllWindow", "CH2", 0));
        label_4->setText(QApplication::translate("ChannelAllWindow", "CH3", 0));
        label_5->setText(QApplication::translate("ChannelAllWindow", "CH4", 0));
        label_6->setText(QApplication::translate("ChannelAllWindow", "CH5", 0));
        label_7->setText(QApplication::translate("ChannelAllWindow", "CH6", 0));
        label_8->setText(QApplication::translate("ChannelAllWindow", "CH7", 0));
        label_9->setText(QApplication::translate("ChannelAllWindow", "CH8", 0));
    } // retranslateUi

};

namespace Ui {
    class ChannelAllWindow: public Ui_ChannelAllWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELALLWINDOW_H
