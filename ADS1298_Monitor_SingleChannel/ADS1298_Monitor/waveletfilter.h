#ifndef WAVELETFILTER_H
#define WAVELETFILTER_H

using namespace std;
#include <QString>
#include <QVector>

#define HardThreshold 1
#define SoftThreshold 0


class WaveletFilter
{
public:
    WaveletFilter();
    WaveletFilter(int dlevel, QString name, int thresholdpattern);
    ~WaveletFilter();
    void setj(int dlevel);
    void setWaveletName(QString name);
    void setMaxSignalLength(int length);
    void setish(int thresholdpattern);
    double filter(double data);
    double getThr(QVector<double> &pDetCoef);
    void Wthresh(
        QVector<double> &pDstCoef,//细节系数（应该是除近似系数外的所有的细节系数）
        double thr,//阈值
        const int gap//跳过最后一层的近似系数,length[0]
        );
    void reset();
    void  wavedec(QVector<double> sig, QVector<double> &c, QVector<int> &length);
    void  dwt(QVector<double> &sig, QVector<double> &A, QVector<double> &D);
    void  waverec(QVector<double> &filterdsig, QVector<double> c, QVector<int> length);
    void  idwt(QVector<double> &output, QVector<double> &A, QVector<double> &D);

private:
    QVector<double> signal;
    int j; //分解水平,Decomposition levels
    QString waveletname;
    QVector<double> filteredsignal;
    int MaxSignalLength;
    int ish; //选择是硬阈值还是软阈值
    QVector<double> LO_D,HI_D,LO_R,HI_R;

};


#endif // WAVELETFILTER_H

