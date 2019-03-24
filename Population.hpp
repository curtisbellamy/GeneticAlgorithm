//
// Created by curti on 2019-03-21.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"
#include <algorithm>

using namespace std;

class Population {
    vector<Tour> populationList;
    const int POPULATION_SIZE = 30;
    const int SHUFFLES = 64;
    const int ITERATIONS = 1000;
    const int MUTATION_RATE = 15;
    const int CITIES_IN_TOUR = 32;


public:
    void addToPopulation(Tour tour);

    void printPopulation();

    void shuffleTours();

    void algorithm();

    void shiftElite();

    Tour breed(Tour& t1, Tour& t2);

    bool mergeConflict(vector<City> vec, City& city);

    Tour chooseCandidate(int n);

    void mutate(Tour& tour);


};


#endif //GENETICALGORITHM_POPULATION_HPP
