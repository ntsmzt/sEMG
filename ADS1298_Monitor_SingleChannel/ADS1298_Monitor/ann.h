#ifndef ANN_H
#define ANN_H

using namespace std;
#include <QString>
#include <QVector>
#include <math.h>

#define NONE  -1
#define LEFT 0
#define RIGHT 1
#define FIST 2
#define SPREAD 3
#define ROCK 4
#define THRESHOLD 0.0002

#define segmentNum 3

#define featureNum 10
#define channelNum 5
#define gestureNum 5

#define input_layer_size featureNum*channelNum
#define hidden_layer_size 30
#define output_layer_size gestureNum



class ANN
{
public:
    ANN();
    ~ANN();
    void getdata(double *channelVol);
    void reset();
    double mean(double *channelVol, int size);
    double mean(QVector<double> &data, int size);
    void abs(double* absdata, QVector<double> &data, int size);
    double abs(double data);
    void square(double *squaredata, QVector<double> &data, int size);
    double sign(double data);
    void multmat(double *theta, double *x, double *y, int m, int n) ;
    void sigmoid(double *data, int size);
    void bias(double *bias_data,double *data, int size);
    void max(double &max_value, int &max_index, double *data, int size);
    double AR(QVector<double> &data, int m, int size);
    double powerspectrum(QVector<double> &data, int startpoint,int endpoint);
    void recognizor();
    void featureExtract();
    QString getcurrentgesture();
    int getcurrentgestureindex();
    void sort(double *value, int size);

    bool debug;

private:
    QVector<double> inputdata[channelNum];
    double feature[input_layer_size];
    int gestureindex;
    QVector<int> activeindex;

};

#endif // ANN

