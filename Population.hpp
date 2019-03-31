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

public:
    // CONSTANTS
    static const int POPULATION_SIZE = 30;
    static const int SHUFFLES = 64;
    static const int NUM_ITERATIONS = 1000;
    static const int MUTATION_RATE = 15;
    static const int CITIES_IN_TOUR = 32;

    // adds new tour to population list
    void addToPopulation(Tour tour);

    // prints each tour in the population
    void printPopulation();

    // shuffles each tour in the population
    void shuffleTours();

    // main algorithm that carries out the population calculations
    void algorithm();

    // shifts elite tour to the top of the population list
    void shiftElite();

    // returns a child tour after breeding tours t1 and t2
    Tour breed(Tour& t1, Tour& t2);

    // determines whether vec already contains city or not
    bool mergeConflict(vector<City> vec, City& city);

    // chooses the ideal candidate to become a parent from the population list
    Tour chooseCandidate(int n);

    // swaps cities in tour depending on a randomly generated value
    void mutate(Tour tour);

    // calculates the tour with the best fitness out of the current population list
    Tour calcBestFit();

    // returns the index of tour in the population list
    int getIndex(Tour tour);
};


#endif //GENETICALGORITHM_POPULATION_HPP
