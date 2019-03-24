//
// Created by curti on 2019-03-18.
//

#include <random>
#include <chrono>
#include <iomanip>
#include "Tour.hpp"

int Tour::counter = 0;

Tour::Tour() {
    ID = counter++;
}

void Tour::addToTour(City city) {
    masterList.push_back(city);
}

void Tour::addToTourAtIndex(City city, int n) {
    masterList[n] = city;
}

void Tour::shuffle() {
    vector<int> randoms;
    for (int i = 0; i < 32; ++i) {
        randoms.push_back(i);
    }


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(randoms.begin(), randoms.end(), std::default_random_engine(seed));

    for (int j = 0; j < pointerList.size(); ++j) {
        pointerList[j] = &masterList[randoms[j]];
    }

}

void Tour::printTour() {

    for (int i = 0; i < pointerList.size(); ++i) {
        cout << pointerList[i]->getName() << ", " << fixed << setprecision(2) << pointerList[i]->getX() << ", " << pointerList[i]->getY() << endl;
    }
}

void Tour::loadPtrs() {

    for (int j = 0; j < masterList.size(); ++j) {
        City * p;
        pointerList.push_back(p);
    }

    for (int i = 0; i < pointerList.size(); ++i) {
        pointerList[i] = &masterList[i];
    }
}


void Tour::calcFitness() {
    vector<City *>::iterator it1;
    vector<City *>::iterator it2;
    double fitnessSum = 0.0;
    for (it1 = pointerList.begin(), it2 = pointerList.begin() + 1; it2 != pointerList.end(); ++it1, ++it2) {
        City * p1 = *it1;
        City * p2 = *it2;
        fitnessSum += distance(p1, p2);
    }
    size_t index = pointerList.size() - 1;
    fitnessSum += calcDistance(pointerList[0], pointerList[index]);
    fitnessSum = (1/fitnessSum) * 1000;
    fitnessRating = fitnessSum;
}


City& Tour::getCity(int n) {
    return *pointerList[n];
}

double Tour::calcDistance(City *p1, City *p2) {
    double distance;
    double xDiff{pow(p2->getX() - p1->getX(), 2)};
    double yDiff{pow(p2->getY() - p1->getY(), 2)};
    distance = sqrt(xDiff + yDiff);
    return distance;

}

void Tour::addToBackOfTour(City city, int n) {
    auto it = masterList.begin() + n;
    masterList.insert(it, 1, city);
}

Tour& Tour::operator=(Tour rhs) {
    mySwap(*this, rhs);
    return *this;
}

void mySwap(Tour &first, Tour &second) {
    using std::swap;
    swap(first.fitnessRating, second.fitnessRating);
    swap(first.masterList, second.masterList);
    swap(first.pointerList, second.pointerList);
    swap(first.ID, second.ID);
}