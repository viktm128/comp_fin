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


vector<complex<double> > GBM::psi(vector<double> &nu, double alpha, double C) {
    vector<complex<double> > vals(nu.size());
    for (int i = 0; i < nu.size(); i++) {
        complex<double> in(nu[i], -(1 + alpha));
        vals[i] = exp(-pow(vol, 2) * pow(in, 2) * T / 2.0 + complex<double>(0, 1) * ((log(S0) + (r - q - pow(vol, 2) / 2.0) * T) * in));
        vals[i] *= C / complex<double>(alpha, nu[i]) / complex<double>(alpha + 1.0, nu[i]);
    }
    return vals;
}

double GBM::get_discount() {
    return exp(-r * T);
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



