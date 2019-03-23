//
// Created by curti on 2019-03-21.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

using namespace std;

class Population {
    vector<Tour> populationList;


public:
    void addToPopulation(Tour tour);

    void printPopulation();

    void shuffleTours();

    void algorithm();

    void shiftElite();

    Tour breed(Tour& t1, Tour& t2);

    bool mergeConflict(vector<City> vec, City& city);

    Tour chooseCandidate(int n);


};


#endif //GENETICALGORITHM_POPULATION_HPP
