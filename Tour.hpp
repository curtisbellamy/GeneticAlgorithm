//
// Created by curti on 2019-03-18.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include "City.hpp"

class Tour {
    double fitnessRating;
    vector<City> masterList;
    vector<City *> pointerList;
    int ID;
    static int counter;

public:
    static const int CITIES_IN_TOUR = 32;

    // default constructor
    Tour();

    // copy constructor
    Tour(const Tour& tour) : fitnessRating(tour.fitnessRating), masterList(tour.masterList), pointerList(tour.pointerList), ID(tour.ID) {}

    // adds new city to master list
    void addToTour(City city);

    // shuffles pointer list to point at new cities in master list
    void shuffle();

    // prints all the cities in the tour, in order
    void printTour();

    // calculates the total distance on each tour
    void calcFitness();

    // returns the tour ID
    int getID() { return ID; }

    // returns this tour's fitness rating
    double getFitnessRating() { return fitnessRating; }

    // returns the city at index n from the pointer list
    City& getCity(int n);

    // calculates the distance between cities p1 and p2
    double calcDistance(City * p1, City * p2);

    // returns this tour's master list
    vector<City> getMasterList() { return masterList; }

    // overloaded assignment operator
    Tour& operator=(Tour rhs);

    // destructor
    ~Tour() {}

    // mySwap to assist copy constructor in the copy and swap algorithm
    friend void mySwap(Tour& first, Tour& second);

    // assigns a new master list of cities to this tour
    void setMasterList(vector<City> masterList);

    // overloaded less than operator
    friend bool operator<(Tour& lhs, Tour& rhs);

    // overloaded greater than operator
    friend bool operator>(Tour& lhs, Tour& rhs);


};


#endif //GENETICALGORITHM_TOUR_HPP
