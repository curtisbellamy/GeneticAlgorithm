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
    double x = 0.0;   //between 0 and 1000
    double y = 0.0;   //between 0 and 1000

public:
//    double x = 0.0;   //between 0 and 1000
//    double y = 0.0;   //between 0 and 1000

    City();

    City(string name);

    string getName(){ return this->name; }

    double getX() { return this->x; }

    double getY() { return this->y; }

    friend bool operator==(City &lhs, City& rhs);

    friend bool operator!=(City &lhs, City& rhs);


};


#endif //GENETICALGORITHM_CITY_HPP
