#ifndef CHANNELALLWINDOW
#define CHANNELALLWINDOW

#include <QMainWindow>
#include "qcustomplot.h"
#include <QVector>

namespace Ui {
class ChannelAllWindow;
}

class ChannelAllWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChannelAllWindow(QWidget *parent = 0);
    ~ChannelAllWindow();
    void setCustomPlotPattern(double TIME_SPAN, double TIME_BORDER);
    void setCustomPlotData(double t, double *channelVol, double TIME_SPAN, double TIME_BORDER, double *lowerbound, double *upperbound);
    void closeEvent(QCloseEvent *event);
    void reset();
    bool isWindowClosed();
    void changeWindowState(bool state);


private slots:


private:
    Ui::ChannelAllWindow *ui;
    QVector<QCustomPlot*> customPlot;
    bool isChannelAllWindowClosed;

};



#endif // CHANNELALLWINDOW

