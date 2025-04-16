#pragma once


#include "ClassObj.hpp"
#include <iostream>

using namespace std;

bool Readfile(const string& inputFile, 
    size_t& n,                      
    double& S,
    double*& w,      
    double*& r);
//apro e leggo il file data.txt

double RateOfReturn(const size_t& n,
    const double* const& w,
    const double* const& r);
//calcolo il rate of return dell'investimento

double saldofinale(const size_t& n,
    const double & S,
    const double& R);
//calcolo del saldo finale 

string ArrayToString(const size_t& n,
    const double* const& v,
    const string& stringa):
//preparo la stampa su result dei due vettori 

bool ExportResult(const string& outputFile,
    const size_t& n,
    const double& S,
    const double* const& w,
    const double* const& r,
    const double& R,   
    const double& V);
//stampa su file result.txt tutto quello che viene richiesto
