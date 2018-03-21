#include "mainwindow.h"
#include <QApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*    unsigned char c0,c1,c2;
    c0 = c1 = 0xff;
    c2 = 0xff;
    unsigned int b = (unsigned int(0xff)<<24) | (unsigned int(c0)<<16) | (unsigned int(c1)<<8) | (unsigned int(c2));
    //unsigned int b = (0xff<<24)+(0xff<<16)+(0xff<<8)+0xff;
    int b1 = b;
    char a1 = 0xff;
    c0 = a1;
    qDebug()<<b<<b1<<c0<<a1;
    */
   return a.exec();
}
