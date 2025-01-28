//
// Created by vikra on 1/24/2025.
//
#pragma once
#include<vector>

#ifndef EUROPEAN_H
#define EUROPEAN_H

class European {
public:
    European(double strike, double maturity);
    virtual ~European() = default;
    double get_strike() const {return K;}
    double get_maturity() const {return T;}
    virtual double payoff(double Xt) = 0;
    std::vector<double> payoffs(std::vector<double> &Xt);
protected:
    double K;
    double T;
};

class EuropeanCall : public European {
public:
    EuropeanCall(double strike, double maturity);
    double payoff(double Xt) override;
};

class EuropeanPut : public European {
public:
    EuropeanPut(double strike, double maturity);
    double payoff(double Xt) override;
};

#endif //EUROPEAN_H
