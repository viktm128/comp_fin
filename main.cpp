#include <iostream>
#include <cmath>
#include <complex>
#include "european.h"
#include "integral.h"
#include "asset_models.h"
#include "fast_fourier.h"

using namespace std;

int main() {
    GBM model(100, 0.05, 0.01, 0.3, 1.0);
    cout << model.BSMCall(90) << endl;
    cout << ft_call(model, log(90)) << endl;
    cout << model.BSMPut(90) << endl;
    cout << ft_put(model, log(90));
    return 0;
}
