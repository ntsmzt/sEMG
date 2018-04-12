#include "waveletfilter.h"
#include<cmath>
double db1[4][2]={{0.707106781186548,0.707106781186548},
                  {-0.707106781186548,0.707106781186548},
                  {0.707106781186548,0.707106781186548},
                  {0.707106781186548,-0.707106781186548}};
double db2[4][4]={{-0.129409522550921,0.224143868041857,0.836516303737469,0.482962913144690},
                  {-0.482962913144690,0.836516303737469,-0.224143868041857,-0.129409522550921},
                  {0.482962913144690,0.836516303737469,0.224143868041857,-0.129409522550921},
                  {-0.129409522550921,-0.224143868041857,0.836516303737469,-0.482962913144690}};
double db3[4][6]={{0.0352262918821007,-0.0854412738822415,-0.135011020010391,0.459877502119331,0.806891509313339,0.332670552950957},
                  {-0.332670552950957,0.806891509313339,-0.459877502119331,-0.135011020010391,0.0854412738822415,0.0352262918821007},
                  {0.332670552950957,0.806891509313339,0.459877502119331,-0.135011020010391,-0.0854412738822415,0.0352262918821007},
                  {0.0352262918821007,0.0854412738822415,-0.135011020010391,-0.459877502119331,0.806891509313339,-0.332670552950957}};
double db4[4][8]={{-0.0105974017849973,0.0328830116669829,0.0308413818359870,-0.187034811718881,-0.0279837694169839,0.630880767929590,0.714846570552542,0.230377813308855},
                  {-0.230377813308855,0.714846570552542,-0.630880767929590,-0.0279837694169839,0.187034811718881,0.0308413818359870,-0.0328830116669829,-0.0105974017849973},
                  {0.230377813308855,0.714846570552542,0.630880767929590,-0.0279837694169839,-0.187034811718881,0.0308413818359870,0.0328830116669829,-0.0105974017849973},
                  {-0.0105974017849973,-0.0328830116669829,0.0308413818359870,0.187034811718881,-0.0279837694169839,-0.630880767929590,0.714846570552542,-0.230377813308855}};
double db5[4][10]={{0.00333572528500155,-0.0125807519990155,-0.00624149021301171,0.0775714938400652,-0.0322448695850295,-0.242294887066190,0.138428145901103,0.724308528438574,0.603829269797473,0.160102397974125},
                   {-0.160102397974125,0.603829269797473,-0.724308528438574,0.138428145901103,0.242294887066190,-0.0322448695850295,-0.0775714938400652,-0.00624149021301171,0.0125807519990155,0.00333572528500155},
                   {0.160102397974125,0.603829269797473,0.724308528438574,0.138428145901103,-0.242294887066190,-0.0322448695850295,0.0775714938400652,-0.00624149021301171,-0.0125807519990155,0.00333572528500155},
                   {0.00333572528500155,0.0125807519990155,-0.00624149021301171,-0.0775714938400652,-0.0322448695850295,0.242294887066190,0.138428145901103,-0.724308528438574,0.603829269797473,-0.160102397974125}};
double db6[4][12]={{-0.00107730108499558,0.00477725751101065,0.000553842200993802,-0.0315820393180312,0.0275228655300163,0.0975016055870794,-0.129766867567096,-0.226264693965169,0.315250351709243,0.751133908021578,0.494623890398385,0.111540743350080},
                  {-0.111540743350080,0.494623890398385,-0.751133908021578,0.315250351709243,0.226264693965169,-0.129766867567096,-0.0975016055870794,0.0275228655300163,0.0315820393180312,0.000553842200993802,-0.00477725751101065,-0.00107730108499558},
                  {0.111540743350080,0.494623890398385,0.751133908021578,0.315250351709243,-0.226264693965169,-0.129766867567096,0.0975016055870794,0.0275228655300163,-0.0315820393180312,0.000553842200993802,0.00477725751101065,-0.00107730108499558},
                  {-0.00107730108499558,-0.00477725751101065,0.000553842200993802,0.0315820393180312,0.0275228655300163,-0.0975016055870794,-0.129766867567096,0.226264693965169,0.315250351709243,-0.751133908021578,0.494623890398385,-0.111540743350080}};


WaveletFilter::WaveletFilter()
{
    j=3;
    setWaveletName("dB6");
    MaxSignalLength=50;
    ish=HardThreshold;
}

WaveletFilter::WaveletFilter(int dlevel, QString name, int thresholdpattern):j(dlevel),ish(thresholdpattern)
{
    MaxSignalLength=50;
    setWaveletName(name);
}

WaveletFilter::~WaveletFilter()
{

}

void WaveletFilter::setj(int dlevel)
{
    j=dlevel;
}

void WaveletFilter::setWaveletName(QString name)
{
    waveletname=name;
    LO_D.clear();
    HI_D.clear();
    LO_R.clear();
    HI_R.clear();
    if (name=="dB1")
    {
        for (int i=0;i<2;i++)
        {
            LO_D.append(db1[0][i]);
            HI_D.append(db1[1][i]);
            LO_R.append(db1[2][i]);
            HI_R.append(db1[3][i]);
        }
    }
    if (name=="dB2")
    {
        for (int i=0;i<4;i++)
        {
            LO_D.append(db2[0][i]);
            HI_D.append(db2[1][i]);
            LO_R.append(db2[2][i]);
            HI_R.append(db2[3][i]);
        }
    }
    if (name=="dB3")
    {
        for (int i=0;i<6;i++)
        {
            LO_D.append(db3[0][i]);
            HI_D.append(db3[1][i]);
            LO_R.append(db3[2][i]);
            HI_R.append(db2[3][i]);
        }
    }
    if (name=="dB4")
    {
        for (int i=0;i<8;i++)
        {
            LO_D.append(db4[0][i]);
            HI_D.append(db4[1][i]);
            LO_R.append(db4[2][i]);
            HI_R.append(db4[3][i]);
        }
    }
    if (name=="dB5")
    {
        for (int i=0;i<10;i++)
        {
            LO_D.append(db5[0][i]);
            HI_D.append(db5[1][i]);
            LO_R.append(db5[2][i]);
            HI_R.append(db5[3][i]);
        }
    }
    if (name=="dB6")
    {
        for (int i=0;i<12;i++)
        {
            LO_D.append(db6[0][i]);
            HI_D.append(db6[1][i]);
            LO_R.append(db6[2][i]);
            HI_R.append(db6[3][i]);
        }
    }
}

void WaveletFilter::setMaxSignalLength(int length)
{
    MaxSignalLength=length;
}

void WaveletFilter::setish(int thresholdpattern)
{
    ish=thresholdpattern;
}


double WaveletFilter::filter(double data)
{
    signal.append(data);
    filteredsignal.clear();

    if (signal.size()>MaxSignalLength)
        signal.removeFirst(); //移除第一个数据
    QVector<double> c;
    QVector<int> length;
    wavedec(signal,c,length);  //小波分解
    QVector<double> det1(length[j]);
    int L=0;
    for (int i=0;i<j;i++)
        L+=length[i];
    for (int i=0;i<length[j];i++)
        det1.append(c[L+i]);
    double threshold=getThr(det1);//求阈值
    Wthresh(c,threshold,length[0]);  //阈值化处理
    waverec(filteredsignal, c, length); //信号重构

    return filteredsignal.back();    //输出滤波后的结果
}


// 根据细节系数，以及信号长度计算阈值
double WaveletFilter::getThr(
    QVector<double> pDetCoef//细节系数（应该是第一级的细节系数）
    )
{
    int detLen=pDetCoef.size();
    double thr = 0.0;
    double sigma = 0.0;

    for (int i = 0; i < detLen; i++)
        pDetCoef[i] = abs(pDetCoef[i]); //取绝对值

    qSort(pDetCoef.begin(),pDetCoef.end()); //升序排列

    if (detLen % 2 == 0 && detLen >= 2)
        sigma = (pDetCoef[detLen / 2-1] + pDetCoef[detLen / 2]) / 2 / 0.6745;
    else
        sigma = pDetCoef[detLen / 2] / 0.6745;

    thr = sigma *sqrt(2.0*log(signal.size()));

    return thr;
}

// 将系数阈值处理，一维二维均适用
void WaveletFilter::Wthresh(
    QVector<double> &pDstCoef,//细节系数（应该是除近似系数外的所有的细节系数）
    double thr,//阈值
    const int gap//跳过最后一层的近似系数,length[0]
    )
{
    int allsize=pDstCoef.size();//分解出来的系数的总长度（非）
    if (ish==HardThreshold)//硬阈值
    {
        for (int i = gap; i < allsize; i++)
        {
            if (abs(pDstCoef[i]) < thr)//小于阈值的置零，大于的不变
                pDstCoef[i] = 0.0;
        }
    }
    else if (ish==SoftThreshold)//软阈值
    {
        for (int i = gap; i < allsize; i++)
        {
            if (abs(pDstCoef[i]) < thr)//小于阈值的置零，大于的收缩
            {
                pDstCoef[i] = 0.0;
            }
            else
            {
                if (pDstCoef[i] < 0.0)
                    pDstCoef[i] = thr - abs(pDstCoef[i]);
                else
                    pDstCoef[i] = abs(pDstCoef[i]) - thr;
            }
        }
    }

}

void WaveletFilter::reset()
{
    signal.clear();
    filteredsignal.clear();
    LO_D.clear();
    HI_D.clear();
    LO_R.clear();
    HI_R.clear();
}

void  WaveletFilter::dwt(QVector<double> &sig, QVector<double> &A, QVector<double> &D)//A 是近似序列，D是细节序列
{
    int srcLen=sig.size();//源信号的长度
    int filterLen=LO_D.size(); //滤波器长度

    //对称拓延
    for(int i=0;i<filterLen-1;i++)
        sig.insert(0,sig[2*i]);
    for(int i=0;i<filterLen-1;i++)
        sig.append(sig[sig.size()-2*i-1]);

    //卷积
    QVector<double> temp_A,temp_D;
    for (int i=0;i<srcLen+filterLen-1;i++)
    {
        double t=0,s=0;
        for (int k=0;k<filterLen;k++){
            t+=sig[i+k]*LO_D[filterLen-1-k];
            s+=sig[i+k]*HI_D[filterLen-1-k];
        }
        temp_A.append(t);
        temp_D.append(s);
    }

    //抽二取样
    int i=1;
    while(i<temp_A.size())
    {
        A.append(temp_A[i]);
        D.append(temp_D[i]);
        i+=2;
    }
    return;
}

void  WaveletFilter::wavedec(QVector<double> signal, QVector<double> &c, QVector<int> &length)
{
    QVector<double> sig(signal);
    int s=sig.size();
    if (s==0)
       return;
    length.insert(0,s);

    for (int k=0;k<j;k++)
    {
        QVector<double> A;
        QVector<double> D;
        dwt(sig,A,D);
        length.insert(0,D.size());
        sig.clear();
        for (int i=0;i<A.size();i++)
            sig.append(A[i]);
        for (int i=0;i<D.size();i++)
            c.insert(0,D[D.size()-1-i]);
        if (k==j-1)
        {
            for (int i=0;i<A.size();i++)
                c.insert(0,A[A.size()-1-i]);
            length.insert(0,A.size());
        }
    }
}

void  WaveletFilter::idwt(QVector<double> &output, QVector<double> &A, QVector<double> &D)//A 是近似序列，D是细节序列
{
    int filterLen=LO_D.size(); //滤波器长度

    //反抽二取样
    int L=A.size();
    for(int i=0;i<L;i++)
    {
        A.insert(2*i,0.0);
        D.insert(2*i,0.0);
    }

    //对称拓延
    filterLen=LO_D.size();
    for(int i=0;i<filterLen-1;i++)
    {
        A.insert(0,A[2*i]);
        D.insert(0,D[2*i]);
    }
    for(int i=0;i<filterLen-1;i++)
    {
        A.append(A[A.size()-2*i-1]);
        D.append(D[D.size()-2*i-1]);
    }

    //卷积
    QVector<double> temp_A,temp_D;
    for (int i=0;i<A.size()+filterLen-1;i++)
    {
        double t=0,s=0;
        for (int k=0;k<filterLen;k++){
            t+=A[i+k]*LO_R[filterLen-1-k];
            s+=D[i+k]*HI_R[filterLen-1-k];
        }
        temp_A.append(t);
        temp_D.append(s);
    }

    //求和
    for(int i=0;i<temp_A.size();i++)
        output.append(temp_A[i]+temp_D[i]);

    return;
}

void  WaveletFilter::waverec(QVector<double> &filterdsig, QVector<double> c, QVector<int> length)
{
    QVector<double> A;
    QVector<double> D;
    for (int i=0;i<length[0];i++)
        A.append(c[i]);

    for (int k=0;k<j;k++)
    {
        D.clear();
        int L=0;
        for (int i=0;i<k+1;i++)
            L+=length[i];
        for (int i=0;i<length[k+1];i++)
            D.append(c[L+i]);

        QVector<double> output;
        idwt(output,A,D);

        if (k<j-1)
        {
            A.clear();
            for (int i=0;i<output.size();i++)
                A.append(output[i]);
        }
        else
        {
            for (int i=0;i<output.size();i++)
                filterdsig.append(output[i]);
        }
    }
}
