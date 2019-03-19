//
// Created by curti on 2019-03-18.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include "City.hpp"

class Tour {

    double fitnessRating;
    vector<City> masterList;
    vector<City *> pointerList;

public:

    void addToTour(City city);

    void shuffle();
};


#endif //GENETICALGORITHM_TOUR_HPP
