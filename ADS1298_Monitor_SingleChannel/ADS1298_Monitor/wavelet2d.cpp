#include "wavelet2d.h"
#include <cmath>

void* dwt(QVector<double> &sig, int J, QString nm, QVector<double> &dwt_output
                , QVector<double> &flag, QVector<int> &length ) {

        int Max_Iter;
        Max_Iter = (int) ceil(log( double(sig.size()))/log (2.0)) - 2;

        if ( Max_Iter < J) {
          J = Max_Iter;
        }

    QVector<double> original_copy,orig, appx_sig, det_sig;
    original_copy = sig;

    // Zero Pad the Signal to nearest 2^ M value ,where M is an integer.
    unsigned int temp_len = sig.size();
        if ( (temp_len % 2) != 0) {
                double temp =sig[temp_len - 1];
                sig.append(temp);
                flag.append(1);
                temp_len++;
        } else {
                flag.sppend(0);
        }
        length.append(temp_len);
        flag.append(double(J));

    orig = sig;


        //  Storing Filter Values for GnuPlot
             QVector<double> lp1,hp1,lp2,hp2;
             filtcoef(nm,lp1,hp1,lp2,hp2);


    for (int iter = 0; iter < J; iter++) {
        dwt1(nm,orig, appx_sig, det_sig);
        dwt_output.insert(dwt_output.begin(),det_sig.begin(),det_sig.end());

        int l_temp = det_sig.size();
        length.insert(length.begin(),l_temp);

        if (iter == J-1 ) {
                dwt_output.insert(dwt_output.begin(),appx_sig.begin(),appx_sig.end());
                int l_temp2 = appx_sig.size();
                length.insert(length.begin(),l_temp2);

        }

        orig = appx_sig;
        appx_sig.clear();
        det_sig.clear();

    }

     sig = original_copy;
        return 0;
}
