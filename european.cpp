//
// Created by vikra on 1/24/2025.
//
#include "european.h"

European::European(double strike, double maturity)
    : K(strike), T(maturity) {}

std::vector<double> European::payoffs(std::vector<double> &Xt) {
    std::vector<double> pi(Xt.size());
    for (int i = 0; i < pi.size(); i++) {
        pi[i] = payoff(Xt[i]);
    }
    return pi;
}



EuropeanCall::EuropeanCall(const double strike, const double maturity)
    : European(strike, maturity) {}

double EuropeanCall::payoff(double Xt) {
    return (Xt < K) ? 0 : Xt - K;
}




EuropeanPut::EuropeanPut(const double strike, const double maturity)
    : European(strike, maturity) {}
double EuropeanPut::payoff(double Xt) {
    return (Xt > K) ? 0 : K - Xt;
}
