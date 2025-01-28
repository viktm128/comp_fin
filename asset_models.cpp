//
// Created by vikra on 1/26/2025.
//
#include <cmath>
#include <complex>
#include "asset_models.h"

// TODO: where to put helper functions?
double normCDF(double x) {
    return 0.5 * erfc(-x * M_SQRT1_2);
}


GBM::GBM(double curr_price, double rate, double dividend_yield, double sig, double maturity)
    : S0(curr_price), r(rate), q(dividend_yield), vol(sig), T(maturity) {}

vector<double> GBM::pdf(vector<double> &ST) {
    vector<double> probs(ST.size());
    for (int i = 0; i < ST.size(); i++) {
        double num = (log(ST[i] / S0) - (r - q - pow(vol, 2) / 2.0) * T) / (vol * sqrt(T));
        probs[i] = exp(-0.5 * pow(num, 2)) / (vol * ST[i] * sqrt(2 * M_PI * T));
    }
    return probs;
}


vector<complex<double> > GBM::char_func(vector<double> &nu) {
    vector<complex<double> > vals(nu.size());
    for (int i = 0; i < nu.size(); i++) {
        vals[i] = exp(
            complex<double>(
                -pow(vol, 2) * pow(nu[i], 2) * T / 2.0, // real part
                (log(S0) + (r - q - pow(vol, 2) / 2.0) * T) * nu[i]) // complex part
                );
    }
    return vals;
}


double GBM::BSMCall(double K) {
    double d1 = (log(S0 / K) + (r - q + pow(vol, 2) / 2.0) * T) / (vol * sqrt(T));
    double d2 = d1 - vol * sqrt(T);
    return  exp(-q * T) * S0 * normCDF(d1) - exp(-r * T) * K * normCDF(d2);
}

double GBM::BSMPut(double K) {
    double d1 = (log(S0 / K) + (r - q + pow(vol, 2) / 2.0) * T) / (vol * sqrt(T));
    double d2 = d1 - vol * sqrt(T);
    return exp(-r * T) * K * normCDF(-d2) - exp(-q * T) * S0 * normCDF(-d1);
}



