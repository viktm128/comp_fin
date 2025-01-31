//
// Created by vikra on 1/26/2025.
//


#ifndef ASSET_MODELS_H
#define ASSET_MODELS_H
#include <vector>
#include <complex>
using namespace std;

class GBM {
public:
    GBM(double curr_price, double rate, double dividend_yield, double sig, double maturity);
    vector<double> pdf(vector<double> &ST);
    vector<complex<double> > psi(vector<double> &nu, double alpha, double C);
    double BSMCall(double K);
    double BSMPut(double K);
    double get_discount();
private:
    double S0;
    double r;
    double q;
    double vol;
    double T;
};


#endif //ASSET_MODELS_H
