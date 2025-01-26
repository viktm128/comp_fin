//
// Created by vikra on 1/24/2025.
//

#ifndef OPTION_H
#define OPTION_H
class Option {
public:
    Option() = default;
    virtual ~Option() = default;
    virtual double payoff(double Xt) = 0;
};
#endif //OPTION_H
