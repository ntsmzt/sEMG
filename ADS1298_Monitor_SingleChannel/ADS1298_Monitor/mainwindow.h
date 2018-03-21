#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "qcustomplot.h"
#include <QLineEdit>
#include <QVector>
#include <QTimer>
#include "channelallwindow.h"

#define TIME_SPAN 5.0
#define TIME_BORDER 0.0

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_open_clicked();
    void readyReadCallback();

    void on_pushButton_send_clicked();

    void on_pushButton_close_clicked();
    void handleReplotTimerTimeout();
    void handleFreshPort();

    void on_pushButton_fresh_clicked();

    void on_pushButton_squareWaveTest_clicked();

    void on_pushButton_noiseTest_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_beginReadC_clicked();

    void on_pushButton_stopReadC_clicked();

    void on_pushButton_clearLog_clicked();

    void on_pushButton_normalTest_clicked();
    double minValue(double beginpoint, double endpoint, int channelIndex);
    double maxValue(double beginpoint, double endpoint, int channelIndex);

    void on_ChannelAllButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QByteArray buffer;
    bool bufferDecoding();
    void setCustomPlotPattern();
    void setCustomPlotData(double, double*);
    int counter;
    QTimer replotTimer;
    bool decodingNewData();
    void log(QString &info);
    int dataNum;
    QVector<QVector<double>> sEMGdata;
    ChannelAllWindow *cwin;
};

#endif // MAINWINDOW_H