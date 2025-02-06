#include <iostream>
#include <cmath>
#include <complex>
#include "european.h"
#include "integral.h"
#include "asset_models.h"
#include "fast_fourier.h"

using namespace std;

int main() {
    GBM model(100, 0.06, 0.01, 1.0, 0.3);
    Heston model2(100, 0.03, 0.0, 0.5, 0.04, 0.5, -0.7, 0.04, 2.0);
    cout << "Black Merton Scholes Pricing: " << endl;
    cout << model.BSMCall(90) << endl;
    cout << ft_call(model, log(90)) << endl;
    cout << model.BSMPut(90) << endl;
    cout << ft_put(model, log(90)) << endl;
    cout << "Heston Stochastic Vol Pricing: " << endl;
    cout << ft_call(model2, log(90)) << endl;
    cout << ft_put(model2, log(90)) << endl;
    return 0;
}
