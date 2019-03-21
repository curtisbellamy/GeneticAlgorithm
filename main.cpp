#include <iostream>
#include <fstream>
#include <sstream>
#include "City.hpp"
#include "Tour.hpp"

int main() {
    Tour tour;

    ifstream infile;
    infile.open("../Cities.txt");
    if(!infile.is_open()){
        cerr << "Unable to open file." << endl;
        exit(1);
    } else {

        string line, name;
        double x, y;
        while(infile >> name >> x >> y){

            City newCity(name, x, y);
            tour.addToTour(newCity);
        }
    }

    tour.loadPtrs();
    tour.printTour();
    cout << endl;
    tour.shuffle();
    tour.printPtrs();




}