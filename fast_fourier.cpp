//
// Created by vikra on 1/24/2025
//

#include "fast_fourier.h"
#include "integral.h"
#include <vector>
#include <cmath>

// TODO: choose better way to adjust ft hyper parameters

double ft_call(EquityModel &model, double k) {
    double B = 250.0;
    double a = 2.0;
    int N = 4096;

    vector<double> nu = range(0.0, B, N);
    vector<complex<double> > integrand = model.psi(nu, a, model.get_discount());
    for (int i = 0; i < integrand.size(); i++) {
        integrand[i] *= exp(complex<double>(0, -nu[i] * k));
    }
    return (exp(-a * k) / M_PI * simpson(nu, integrand)).real();

}

double ft_put(EquityModel &model, double k) {
    double B = 200;
    double a = -2;
    int N = 2048;

    vector<double> nu = range(0.0, B, N);
    vector<complex<double> > integrand = model.psi(nu, a, model.get_discount());
    for (int i = 0; i < integrand.size(); i++) {
        integrand[i] *= exp(complex<double>(0, -nu[i] * k));
    }
    return (exp(-a * k) / M_PI * simpson(nu, integrand)).real();
}
