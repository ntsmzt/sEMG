#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&serialPort,SIGNAL(readyRead()),this,SLOT(readyReadCallback()));
    connect(&replotTimer,SIGNAL(timeout()),this,SLOT(handleReplotTimerTimeout()));

    cwin=new ChannelAllWindow(this);

    for(int i=1; i<=8; i++)
        ui->comboBox_channel->addItem(QString("Channel %1").arg(i));
    ui->comboBox_channel->setCurrentIndex(3);  //默认通道

    handleFreshPort();

    for (int i=0;i<8;++i)
    {
        QVector<double> tmp;
        sEMGdata.append(tmp);
        filteredsEMGdata.append(tmp);
    }
    dataNum=0;
    static double ahp[1]={1.0f};
    static double bhp[5]={0.0627402311,-0.2499714735,0.3744644353,-0.24997147355,0.062740231119};
    static double anotch[7]={1.000000000000000,-1.699163423921474,3.464263380095651,-3.035006841250400,
                         2.930889612822229,-1.213689963509197,0.604109699507278};
    static double bnotch[7]={0.777337677403281,-1.441206975301750,3.222510786578553,-3.065671614896859,
                         3.222258852356618,-1.440981638482467,0.777155376086710};
    for (int i=0;i<8;i++)
    {
        hpfilters[i].initFilter(ahp,bhp,1,5);
        notchfilters[i].initFilter(anotch,bnotch,7,7);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_open_clicked()
{
    int baudRate = ui->comboBox_baudRate->currentText().toInt();
    QString com = ui->portBox->currentText();

    serialPort.setBaudRate(baudRate);
    serialPort.setPortName(com);
    serialPort.open(QIODevice::ReadWrite);

    counter = 0;
    setCustomPlotPattern();
    cwin->setCustomPlotPattern(TIME_SPAN,TIME_BORDER);
    replotTimer.start(100); //10fps
    ui->statusBar->showMessage(tr("Open successed"));
}

void MainWindow::readyReadCallback()
{
    //qDebug()<<"readyReadCallback"<<endl;
    QByteArray r = serialPort.readAll();
    buffer.append(r);    
    while(bufferDecoding());
}


void MainWindow::on_pushButton_send_clicked()
{
    QByteArray ms = ui->lineEdit_send->text().toLocal8Bit();
    serialPort.write(ms);
}

void MainWindow::on_pushButton_close_clicked()
{
    serialPort.close();
    replotTimer.stop();
    ui->statusBar->showMessage(tr("Close successed"));
}

void MainWindow::handleReplotTimerTimeout()
{
    ui->customPlot->replot();
}

void MainWindow::handleFreshPort()
{
    QSerialPortInfo portinfo;
    QList<QSerialPortInfo> ports=portinfo.availablePorts();
    ui->portBox->clear();
    for (int i=0;i<ports.length();i++)
    {
        ui->portBox->addItem(ports.at(i).portName());
    }
}

bool MainWindow::bufferDecoding()
{
    //qDebug()<<"bufferDecoding"<<endl;
    QByteArray packageHead;
    packageHead.append(0xff);
    packageHead.append(0xff);
    int packageBegin = buffer.indexOf(packageHead);
    if(packageBegin == -1) //未检测到数据头，继续读数
        return false;
    if(packageBegin != 0) //检测到数据头，但前面有无效数据，删掉掉
        buffer.remove(0,packageBegin);

    if(buffer.length()<3)
        return false;

    unsigned char cmd = buffer[2];
    if(buffer.length()>=5 && cmd==0x03) //回复命令
    {
        unsigned char value, check;
        value = buffer[3];
        check = buffer[4];
        if(check==value) //数据正确
            log( QString::number(value) );
        else
            log( tr("ERROR!") );
        buffer.remove(0,5);
        return true;
    }

    if(buffer.length()>=31 && cmd==0x01) //数据命令
    {
       // qDebug()<<"data"<<endl;
        decodingNewData();
        return true;
    }
    return false;

}

void MainWindow::setCustomPlotPattern()
{

    ui->customPlot->clearGraphs(); //清除原始数据
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->legend->setFont(QFont("Helvetica",9));
    ui->customPlot->legend->setMaximumSize(20,20);
    ui->customPlot->yAxis->setRange(-0.04,0);
    ui->customPlot->yAxis->setAutoTicks(true);
    ui->customPlot->yAxis->setLabel("Voltage(V)");
    ui->customPlot->xAxis->setRange(0,TIME_SPAN+TIME_BORDER);
    ui->customPlot->xAxis->setLabel("time(s)");
    ui->customPlot->replot();
}

void MainWindow::setCustomPlotData(double t, double * channelVol)
{
    int channelIndex = ui->comboBox_channel->currentIndex();
    ui->customPlot->graph(0)->addData(t, channelVol[channelIndex]);
    if(t<TIME_SPAN)
    {
        ui->customPlot->xAxis->setRange(0,TIME_SPAN+TIME_BORDER);
        ui->customPlot->yAxis->setRange(minValue(1,dataNum,channelIndex),maxValue(1,dataNum,channelIndex));
    }
    else
    {
        ui->customPlot->graph(0)->removeDataBefore(t-TIME_SPAN);
        ui->customPlot->xAxis->setRange(t-TIME_SPAN,t+TIME_BORDER);
        ui->customPlot->yAxis->setRange(minValue(dataNum-1250,dataNum,channelIndex),maxValue(dataNum-1250,dataNum,channelIndex));
    }

    ui->lineEdit_channel->setText(QString("%1").arg(channelVol[channelIndex],0,'g',2));

}

bool MainWindow::decodingNewData()
{
    int dataIndex = 6;
    unsigned char sum = 0;
    unsigned char data[3];
    int channelVal[8];
    for(int i=0; i<8; i++) //对每个通道
    {
        for(int j=0; j<3;j++) // 读取数据
        {
            data[j] = buffer[dataIndex++];
            sum += data[j];
        }
        if( (data[0]&0x80)!=0x80 ) //最高位为0，表示输出为整数
        {
            unsigned int val = ((unsigned int)(data[0])<<16) | ((unsigned int)(data[1])<<8) | ((unsigned int)(data[2]));
            channelVal[i] = val;
        }
        else //最高位为1，输出为负数，需要转化为补码
        {
            unsigned int val = 0xff000000 | ((unsigned int)(data[0])<<16) | ((unsigned int)(data[1])<<8) | ((unsigned int)(data[2])); //取符号位之后的数值
            channelVal[i] =val;
        }
    }

    unsigned char check = buffer[30];
    buffer.remove(0,31);//移除数据

//    if(sum!=check)
//        return false;

    double channelVol[8];
    for(int i=0; i<8; i++)
    {
        channelVol[i] = double(channelVal[i]) / 0x7FFFFE * 3.3; //转化为电压值
        //qDebug()<<i<<'\t'<<channelVol[i]<<endl;
    }

    double t = (counter++) / 250.0;
    dataNum++;
    double filteredchannelVol[8];
    for(int i=0;i<8;i++)
    {
        sEMGdata[i].append(channelVol[i]);
        double filteredData=notchfilters[i].filter(channelVol[i]);
        filteredchannelVol[i]=hpfilters[i].filter(filteredData);
        if (dataNum>50)
            filteredchannelVol[i]=waveletfilter[i].filter(filteredchannelVol[i]);
        filteredsEMGdata[i].append(filteredchannelVol[i]);
    }

    setCustomPlotData(t,filteredchannelVol);
    cwin->setCustomPlotData(t,filteredsEMGdata,TIME_SPAN,TIME_BORDER,dataNum);
    return true;
}

void MainWindow::log(QString info)
{
    ui->textBrowser_log->append(info);
}

void MainWindow::on_pushButton_fresh_clicked()
{
    handleFreshPort();
}

void MainWindow::on_pushButton_squareWaveTest_clicked()
{
    unsigned char cmd[] = {0x05};
    if (!serialPort.isOpen())
        return;
    serialPort.write((char *)cmd,1);
}

void MainWindow::on_pushButton_noiseTest_clicked()
{
    unsigned char cmd[] = {0x04};
    if (!serialPort.isOpen())
        return;
    serialPort.write((char *)cmd,1);
}

void MainWindow::on_pushButton_reset_clicked()
{
    unsigned char cmd[] = {0x80};
    if (!serialPort.isOpen())
        return;
    serialPort.write((char *)cmd,1);
}

void MainWindow::on_pushButton_beginReadC_clicked()
{
    unsigned char cmd[] = {0x10};
    if (!serialPort.isOpen())
        return;
    serialPort.write((char *)cmd,1);
}

void MainWindow::on_pushButton_stopReadC_clicked()
{
    unsigned char cmd[] = {0x11};
    if (!serialPort.isOpen())
        return;
    serialPort.write((char *)cmd,1);
}

void MainWindow::on_pushButton_clearLog_clicked()
{
    ui->textBrowser_log->clear();
}

void MainWindow::on_pushButton_normalTest_clicked()
{
    unsigned char cmd[] = {0x06};
    if (!serialPort.isOpen())
        return;
    serialPort.write((char *)cmd,1);
}

double MainWindow::minValue(double beginpoint, double endpoint, int channelIndex)
{
    double minimumValue=filteredsEMGdata[channelIndex][beginpoint-1];
    for (int i=beginpoint;i<endpoint;i++)
    {
        if (filteredsEMGdata[channelIndex][i]<minimumValue)
            minimumValue=filteredsEMGdata[channelIndex][i];
    }
    minimumValue*=1.25;
    return -0.04<minimumValue?-0.04:minimumValue;
}

double MainWindow::maxValue(double beginpoint, double endpoint, int channelIndex)
{
    double maximumValue=filteredsEMGdata[channelIndex][beginpoint-1];
    for (int i=beginpoint;i<endpoint;i++)
    {
        if (filteredsEMGdata[channelIndex][i]>maximumValue)
            maximumValue=filteredsEMGdata[channelIndex][i];
    }
    maximumValue*=1.25;
    return 0.04>maximumValue?0.04:maximumValue;
}

void MainWindow::on_ChannelAllButton_clicked()
{
    cwin->show();
}

void MainWindow::on_savebutton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
         tr("��������"),
         "",
         tr("�����ļ�"));
    if (!fileName.isNull())
    {
        //fileName���ļ���
        saveData(fileName);
    }
    else
    {
     //������ȡ??
    }
     return;
}

int MainWindow::saveData(QString &filename)
{
    QString rawdatafilename=filename+".rawdat";
    QString filtereddatafilename=filename+".filtereddat";
    QFile frawdata(rawdatafilename);
    if(!frawdata.open(QIODevice::WriteOnly | QIODevice::Text))
    {
     printf("Open failed.");
     return -1;
    }
    QFile ffiltereddata(filtereddatafilename);
    if(!ffiltereddata.open(QIODevice::WriteOnly | QIODevice::Text))
    {
     printf("Open failed.");
     return -1;
    }

    QTextStream txtOutputrawdata(&frawdata);
    QTextStream txtOutputfiltereddata(&ffiltereddata);
    /*
    txtOutputrawdata<<"counter"<<'\t';
    txtOutputfiltereddata<<"counter"<<'\t';
    for (int i=0;i<8;i++){
        txtOutputrawdata<<"CH"<<i+1<<'\t';
        txtOutputfiltereddata<<"CH"<<i+1<<'\t';
    }
    txtOutputrawdata<<endl;
    txtOutputfiltereddata<<endl;
    */
    for (int i=0;i<sEMGdata[0].length();i++)
    {
        txtOutputrawdata<<i+1<<'\t';
        for (int j=0;j<8;j++)
            txtOutputrawdata<<sEMGdata[j][i]<<'\t';
        txtOutputrawdata<<endl;
    }
    for (int i=0;i<filteredsEMGdata[0].length();i++)
    {
        txtOutputfiltereddata<<i+1<<'\t';
        for (int j=0;j<8;j++)
            txtOutputfiltereddata<<filteredsEMGdata[j][i]<<'\t';
        txtOutputfiltereddata<<endl;
    }
    frawdata.close();
    ffiltereddata.close();;

    return 0;
}
