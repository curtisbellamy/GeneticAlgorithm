//
// Created by curti on 2019-03-18.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <iostream>
#include <vector>

using namespace std;

class City {

    string name;
    double x;   //between 0 and 1000
    double y;   //between 0 and 1000

public:

    City();

    City(string name);

    string getName(){ return name; }

    double getX() { return x; }

    double getY() { return y; }

    friend bool operator==(City &lhs, City& rhs);

    friend bool operator!=(City &lhs, City& rhs);


};


#endif //GENETICALGORITHM_CITY_HPP
