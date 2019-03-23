//
// Created by curti on 2019-03-18.
//

#include <random>
#include "City.hpp"

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0,1000.0);

City::City(string name) : name(name) {

    x = distribution(generator);
    y = distribution(generator);
}

City::City() {}

bool operator==(City &lhs, City &rhs) {
    if(lhs.getName() != rhs.getName())
        return false;

    return true;
}

bool operator!=(City &lhs, City &rhs) {
    if(lhs.getName() != rhs.getName())
        return true;
    return false;
}
