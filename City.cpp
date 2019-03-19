//
// Created by curti on 2019-03-18.
//

#include "City.hpp"

City::City(string name, int x, int y) : name(name), x(x), y(y) {
    if(x < 0 || x > 1000){
        cerr << "Error! X coordinate cannot be less than 0 or greater than 1000." << endl;
        exit(1);
    }
    if(y < 0 || y > 1000){
        cerr << "Error! Y coordinate cannot be less than 0 or greater than 1000." << endl;
        exit(1);
    }
}
