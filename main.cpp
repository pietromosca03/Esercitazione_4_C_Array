#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    double *w= nullptr; 
    double *r= nullptr; 
    double S;
    size_t n;

    if(!Readfile("../data.txt",n,S,w,r))
    return 1;

    double R = RateOfreturn(n,w,r);
    double V = Finalvalue(n,S,R); 


    if (!ExportResult("result.txt", n, S, w, r, R, V)) {
        cerr << "impossibile creare o sovrascrivere il file result.txt" << endl;
        delete[] w;
        delete[] r;

        return 1;
    }

    cout << fixed << setprecision(2)<<"S = " << S  <<" , n = " << n << endl;
    cout << ArrayToString(n, w, "w") << endl;  //se escono numeri a caso:  segno chiarissimo che la memoria non è stata inizializzata correttamente, cioè stai leggendo numeri a caso dalla RAM.  
    cout << ArrayToString(n, r, "r") << endl;
    cout << setprecision(4) << "Rate of return of the portfolio : " << R << endl;
    cout << fixed << setprecision(2)<<"V = "<< V << endl;

    delete[] w;
    delete[] r;


    return 0;
}

