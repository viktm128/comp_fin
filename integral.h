//
// Created by vikra on 1/26/2025.
//

#ifndef INTEGRAL_H
#define INTEGRAL_H

template <typename T>
T trapezoid(std::vector<double> x,std::vector<T> f) {
    T sum = 0;
    for (int i = 1; i < x.size(); i++) {
        sum += (x[i] - x[i - 1]) * (f[i] + f[i - 1]) / 2;
    }
    return sum;
}

template <typename T>
T simpson(std::vector<double> x, std::vector<T> f) {
    // REQUIRES x to be equally spaced and n odd;
    size_t n = x.size();
    double h = x[1] - x[0];
    T sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == x.size() - 1) sum += f[i];
        else if (i % 2 == 0) sum += 2.0 * f[i];
        else sum += 4.0 * f[i];
    }
    return 1.0/3.0 * h * sum;
}

template<typename T>
std::vector<T> range(T a, T b, int N) {
    std::vector<T> vals(N + 1);
    vals[0] = a;
    for (int i = 1; i < N + 1; i++) {
        vals[i] = (b - a) / (double)N + vals[i - 1];
    }
    return vals;
}
#endif //INTEGRAL_H
