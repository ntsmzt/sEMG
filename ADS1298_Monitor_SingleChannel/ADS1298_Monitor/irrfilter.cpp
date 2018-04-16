#include "iirfilter.h"

IIRFilter::IIRFilter()
{

}

int IIRFilter::initFilter(double atmp[], double btmp[], int nal, int nbl)
{

    al=nal;
    bl=nbl;

    a.clear();
    b.clear();
    xtmp.clear();
    ytmp.clear();

    for (int i=0;i<al;i++)
        a.append(atmp[i]);

    for (int i=0;i<bl;i++)
        b.append(btmp[i]);
    return 0;
}

double IIRFilter::filter(double data)
{
    ytmp.push_front(0); //Inserts value at the beginning of the list.

    xtmp.insert(0,data);// Inserts value at index position i in the list.
    //If i is 0, the value is prepended to the list.
    //If i is size(), the value is appended to the list.

    if (xtmp.length()>bl)
        xtmp.pop_back(); //移除最后一个数据
    for (int i=0;i<bl;i++)
    {
        if (i==xtmp.length())
            break;
        ytmp[0]+=xtmp[i]*b[i];  //xtemp ytemp 倒序存储
    }

    if (ytmp.length()>al)
        ytmp.pop_back();   //移除最后一个数据
    for (int i=1;i<al;i++)  //i从1开始
    {
        if (i==ytmp.length())
            break;
        ytmp[0]-=ytmp[i]*a[i];
    }
    ytmp[0]/=a[0];
    return ytmp[0];    //输出IIR滤波后的结果
}

int IIRFilter::reset()
{
    xtmp.clear();
    ytmp.clear();
    return 0;
}


