//
// Created by curti on 2019-03-18.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "City.hpp"

class Tour {

    double fitnessRating;
    vector<City> masterList;
    vector<City *> pointerList;

public:

    Tour();

    void addToTour(City city);

    void shuffle();

    void printTour();

    void printPtrs();

    void loadPtrs();

    bool ifGenerated(vector<int> generated, int rand);

};


#endif //GENETICALGORITHM_TOUR_HPP
