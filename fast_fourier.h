//
// Created by vikra on 1/24/2025.
//

#ifndef FAST_FOURIER_H
#define FAST_FOURIER_H

#include "asset_models.h"


double ft_call(EquityModel &model, double k);
double ft_put(EquityModel &model, double k);

vector<double> fft_call(GBM model, vector<double> k);
vector<double> fft_put(GBM model, vector<double> k);

#endif //FAST_FOURIER_H
