//
// Created by vikra on 1/24/2025.
//

#ifndef FAST_FOURIER_H
#define FAST_FOURIER_H

#include "asset_models.h"
#include <fzftw3.h>

double ft_call(GBM model, double k);
double ft_put(GBM model, double k);

vector<double> fft_call(GBM model, vector<double> k);
vector<double> fft_put(GBM model, vector<double> k);

#endif //FAST_FOURIER_H
