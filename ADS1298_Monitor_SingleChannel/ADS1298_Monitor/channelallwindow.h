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
    void setCustomPlotData(double t, QVector< QVector<double> > sEMGdata, double TIME_SPAN, double TIME_BORDER, int dataNum);
    double minValue(double beginpoint, double endpoint, int channelIndex, QVector< QVector<double> > sEMGdata);
    double maxValue(double beginpoint, double endpoint, int channelIndex, QVector< QVector<double> > sEMGdata);

private slots:


private:
    Ui::ChannelAllWindow *ui;
    QVector<QCustomPlot*> customPlot;

};



#endif // CHANNELALLWINDOW

