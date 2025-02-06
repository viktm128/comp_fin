//
// Created by vikra on 1/26/2025.
//


#ifndef ASSET_MODELS_H
#define ASSET_MODELS_H
#include <vector>
#include <complex>
using namespace std;

class EquityModel {
public:
    EquityModel(double spot, double rate, double div, double time);
    double get_discount();
    virtual ~EquityModel();
    virtual vector<complex<double> > psi(vector<double> &nu, double alpha, double C) = 0;
protected:
    double S0;
    double r;
    double q;
    double T;
};

class Heston : public EquityModel {
public:
    Heston(double spot, double rate, double div, double time, double vol_init, double vol_of_vol, double corr, double vol_mean, double vol_speed);
    vector<complex<double> > psi(vector<double> &nu, double alpha, double C) override;
private:
    double kappa;
    double theta;
    double rho;
    double sig;
    double v0;
};

class GBM : public EquityModel {
public:
    GBM(double curr_price, double rate, double dividend_yield, double maturity, double sig);
    vector<double> pdf(vector<double> &ST);
    vector<complex<double> > psi(vector<double> &nu, double alpha, double C) override;
    double BSMCall(double K);
    double BSMPut(double K);
private:
    double vol;
};


#endif //ASSET_MODELS_H
