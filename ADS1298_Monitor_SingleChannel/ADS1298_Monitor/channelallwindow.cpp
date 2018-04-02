#include "channelallwindow.h"
#include "ui_channelallwindow.h"


ChannelAllWindow::ChannelAllWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChannelAllWindow),
    customPlot(8)
{
    ui->setupUi(this);

    customPlot[0] = ui->customPlot1;
    customPlot[1] = ui->customPlot2;
    customPlot[2] = ui->customPlot3;
    customPlot[3] = ui->customPlot4;
    customPlot[4] = ui->customPlot5;
    customPlot[5] = ui->customPlot6;
    customPlot[6] = ui->customPlot7;
    customPlot[7] = ui->customPlot8;

}

ChannelAllWindow::~ChannelAllWindow()
{
    delete ui;
}


void ChannelAllWindow::setCustomPlotPattern(double TIME_SPAN, double TIME_BORDER)
{


    QPen pen[8] = {QPen(Qt::red), QPen(Qt::magenta), QPen(Qt::yellow), QPen(Qt::green), \
                   QPen(Qt::blue),   QPen(Qt::cyan), QPen(Qt::darkBlue), QPen(Qt::black) };
    for(int i=0;i<8; i++)
    {
        customPlot[i]->clearGraphs(); //清除原始数据
        customPlot[i]->addGraph();
        customPlot[i]->graph(0)->setPen(pen[i]);
        customPlot[i]->graph(0)->setLineStyle(QCPGraph::lsLine);
        customPlot[i]->graph(0)->setName(QString("Ch%1").arg(i+1));
        customPlot[i]->legend->setVisible(true);   //打开图例
        customPlot[i]->legend->setFont(QFont("Helvetica",9));
        customPlot[i]->legend->setMaximumSize(20,20);
        customPlot[i]->yAxis->setRange(-0.04,0.04);
        customPlot[i]->yAxis->setLabel("Voltage(V)");
        customPlot[i]->xAxis->setRange(0,TIME_SPAN+TIME_BORDER);
        customPlot[i]->xAxis->setLabel("time(s)");
        customPlot[i]->replot();
    }

}

void ChannelAllWindow::setCustomPlotData(double t, QVector<QVector<double>> sEMGdata, double TIME_SPAN, double TIME_BORDER, int dataNum)
{
    for(int i=0; i<8; i++)
    {
        customPlot[i]->graph(0)->addData(t, sEMGdata[i].back());
        if(t<TIME_SPAN)
        {
            customPlot[i]->xAxis->setRange(0,TIME_SPAN+TIME_BORDER);
            customPlot[i]->yAxis->setRange(minValue(1,dataNum,i,sEMGdata),maxValue(1,dataNum,i,sEMGdata));
        }
        else
        {
            customPlot[i]->graph(0)->removeDataBefore(t-TIME_SPAN);
            customPlot[i]->xAxis->setRange(t-TIME_SPAN,t+TIME_BORDER);
            customPlot[i]->yAxis->setRange(minValue(dataNum-TIME_SPAN*1250,dataNum,i,sEMGdata),maxValue(dataNum-TIME_SPAN*1250,dataNum,i,sEMGdata));
        }
        customPlot[i]->replot();
    }
}

double ChannelAllWindow::minValue(double beginpoint, double endpoint, int channelIndex, QVector<QVector<double>> sEMGdata)
{
    double minimumValue=sEMGdata[channelIndex][beginpoint-1];
    for (int i=beginpoint;i<endpoint;i++)
    {
        if (sEMGdata[channelIndex][i]<minimumValue)
            minimumValue=sEMGdata[channelIndex][i];
    }
    minimumValue*=1.25;
    return -0.04<minimumValue?-0.04:minimumValue;
}

double ChannelAllWindow::maxValue(double beginpoint, double endpoint, int channelIndex, QVector<QVector<double>> sEMGdata)
{
    double maximumValue=sEMGdata[channelIndex][beginpoint-1];
    for (int i=beginpoint;i<endpoint;i++)
    {
        if (sEMGdata[channelIndex][i]>maximumValue)
            maximumValue=sEMGdata[channelIndex][i];
    }
    maximumValue*=1.25;
    return 0.04>maximumValue?0.04:maximumValue;
}
