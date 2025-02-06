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


EquityModel::EquityModel(double spot, double rate, double div, double time)
    : S0(spot), r(rate), q(div), T(time) {}

EquityModel::~EquityModel() = default;

double EquityModel::get_discount() {
    return exp(-r * T);
}

Heston::Heston(double spot, double rate, double div, double time, double vol_init, double vol_of_vol, double corr, double vol_mean, double vol_speed)
    : EquityModel(spot, rate, div, time), kappa(vol_speed), theta(vol_mean), rho(corr), sig(vol_of_vol), v0(vol_init) {}

vector<complex<double> > Heston::psi(vector<double> &nu, double alpha, double C) {
    vector<complex<double> > vals(nu.size());
    complex<double> i(0.0, 1.0);
    for (int j = 0; j < nu.size(); j++) {
        complex<double> u(nu[j], -(1 + alpha));
        complex<double> gamma = gamma = sqrt(pow(sig, 2) * (pow(u, 2) + u * i) + pow(kappa - i * rho * sig* u, 2));
        complex<double> num1, denom1, num2, denom2;
        num1 = exp(i * u * (log(S0) + (r - q) * T) + (kappa * theta * T * (kappa - i * rho * sig * u)) / (pow(sig, 2)));
        denom1 = pow(cosh(gamma * T / 2.0) + (kappa - i * rho * sig * u) / (gamma) * sinh(gamma * T / 2.0), 2 * kappa * theta / pow(sig, 2));
        num2 = -(pow(u, 2) + i * u) * v0;
        denom2 = gamma / tanh(gamma * T / 2.0) + kappa - i * rho * sig * u;
        vals[j] = num1 / denom1 * exp(num2 / denom2);
        vals[j] *= C / complex<double>(alpha, nu[j]) / complex<double>(alpha + 1.0, nu[j]);
    }
    return vals;
}



GBM::GBM(double curr_price, double rate, double dividend_yield, double time, double sig)
    : EquityModel(curr_price, rate, dividend_yield, time), vol(sig) {}

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



