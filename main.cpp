#include <iostream>
#include <fstream>
#include <sstream>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"

int main() {

    Population population;

    for (int i = 0; i < 30; ++i) {

        Tour tour;

        ifstream infile;
        infile.open("../Cities.txt");
        if (!infile.is_open()) {
            cerr << "Unable to open file." << endl;
            exit(1);
        } else {

            string line, name;
            while (infile >> name) {

                City newCity(name);
                tour.addToTour(newCity);
            }
            population.addToPopulation(tour);

        }
    }

    population.shuffleTours();
    population.algorithm();








}