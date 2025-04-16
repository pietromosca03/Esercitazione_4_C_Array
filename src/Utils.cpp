#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include <iomanip>

using namespace std;

bool Readfile(const string& inputFile, 
    size_t& n,                      
    double& S,
    double*& w,      
    double*& r)
{
    ifstream file (inputFile);  
    if(file.fail()) {
        cout << "Errore: file non trovato o impossibile da aprire" << endl;
        return false;
    }

    string riga;
    size_t rigacorrente = 0; 
    size_t indicearray = 0;

    while(getline(file,riga)){
        stringstream ss;
        ss.str(riga);
        string primastringa;
        string secondastringa;
        if (getline(ss,primastringa,';') && getline(ss,secondastringa)){
            if (rigacorrente==0){
                S = stod(secondastringa);
            }

            else if (rigacorrente==1){
                n=stoi(secondo);
                w = new double[n]; 
                r = new double[n];
            }

            else if (rigacorrente > 2 && indicearray < n){
                w[indicearray]=(stod(primastringa)); 
                r[indicearray]=(stod(secondastringa));
                indicearray ++;
            }
        }

        rigacorrente++;

    }
        return true;
}

double RateOfReturn(const size_t& n,
    const double* const& w,
    const double* const& r)
{
    double  R = 0.0;

    for (int i=0; i<n; i++){
        R+= w[i]*r[i];
    }

    return R;
}

double saldofinale(const size_t& n,
    const double & S,
    const double& R)
{
    double V = S*( 1+R );

    return V;
}

string ArrayToString(const size_t& n,
    const double* const& v,
    const string& stringa)  {

    ostringstream toString; 
    toString << stringa << " = [ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";    
    return toString.str(); 
}

bool ExportResult(const string& outputFile,
    const size_t& n,
    const double& S,
    const double* const& w,
    const double* const& r,
    const double& R,   
    const double& V)
{
    ofstream file(result); 

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2)<<"S = " << S  <<" , n = " << n << endl;
    file << ArrayToString(n, w, "w") << endl;   
    file << ArrayToString(n, r, "r") << endl;
    file<< setprecision(4) << "Rate of return of the portfolio : " << R << endl;
    file << fixed << setprecision(2)<<"V: "<< V << endl;
   
    file.close();

    return true; 
}