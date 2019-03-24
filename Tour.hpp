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
    int ID;
    static int counter;

public:

    Tour();

    Tour(const Tour& tour) : fitnessRating(tour.fitnessRating), masterList(tour.masterList), pointerList(tour.pointerList), ID(tour.ID) {}

    void addToTour(City city);

    void addToBackOfTour(City city, int n);

    void addToTourAtIndex(City city, int n);

    void shuffle();

    void printTour();

    void loadPtrs();

    void calcFitness();

    int getID() { return ID; }

    double getFitnessRating() { return fitnessRating; }

    City& getCity(int n);

    double calcDistance(City * p1, City * p2);

    vector<City> getMasterList() { return masterList; }

    Tour& operator=(Tour rhs);

    ~Tour() {}

    friend void mySwap(Tour& first, Tour& second);




};


#endif //GENETICALGORITHM_TOUR_HPP
