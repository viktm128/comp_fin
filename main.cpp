#include <iostream>
#include "european.h"

using namespace std;

int main() {
    EuropeanCall x = EuropeanCall(100, 2);
    EuropeanPut y = EuropeanPut(100, 2);

    vector<double> samplePrices(10);
    for (int i = 0; i < 10; i++) {
        samplePrices[i] = 90 + 2*i;
    }

    vector<double> xpi = x.payoffs(samplePrices);
    vector<double> ypi = y.payoffs(samplePrices);
    for (int i = 0; i < 10; i++) {
        cout << "Price = " << samplePrices[i] << ", Call payoff = " << xpi[i] << ", Put payoff = " << ypi[i] << endl;
    }
    return 0;
}
