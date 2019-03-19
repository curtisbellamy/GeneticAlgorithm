//
// Created by curti on 2019-03-18.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <iostream>
#include <vector>

using namespace std;

class City {

    const static string cityNames[];
    string name;
    double x;   //between 0 and 1000
    double y;   //between 0 and 1000

public:
    City(string name, int x, int y);


};


#endif //GENETICALGORITHM_CITY_HPP
