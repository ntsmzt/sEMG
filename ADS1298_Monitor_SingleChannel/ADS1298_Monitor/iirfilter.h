#ifndef IIRFILTER_H
#define IIRFILTER_H

#include <QList>


class IIRFilter
{
public:
    IIRFilter();
    int initFilter(double atmp[],double btmp[],int nal,int nbl);
    double filter(double data);
    int reset();


private:
    QList<double> a,b;  //系数序列
    int al,bl; //系数序列的长度
    QList<double> xtmp,ytmp;
};

#endif // IIRFILTER_H
