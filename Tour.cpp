//
// Created by curti on 2019-03-18.
//

#include <random>
#include <chrono>
#include "Tour.hpp"

Tour::Tour() {

}

void Tour::addToTour(City city) {
    masterList.push_back(city);
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
    for (int i = 0; i < masterList.size(); ++i) {
        cout << masterList[i].getName() << ", " << masterList[i].getY() << ", " << masterList[i].getY() << endl;
    }
}

void Tour::printPtrs() {

    for (int i = 0; i < pointerList.size(); ++i) {
        cout << pointerList[i]->getName() << ", " << pointerList[i]->getX() << ", " << pointerList[i]->getY() << endl;
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

bool Tour::ifGenerated(vector<int> generated, int rand) {
    for (int i = 0; i < generated.size(); ++i) {
        if(generated[i] == rand)
            return true;
    }
    return false;
}

void Tour::calcFitness() {
    vector<City *>::iterator it1;
    vector<City *>::iterator it2;
    double fitnessSum = 0;
    for (it1 = pointerList.begin(), it2 = pointerList.begin() + 1; it2 != pointerList.end(); ++it1, ++it2) {
        City * p = *it1;
        City * p2 = *it2;
        double xDiff{abs(p->getX() - p2->getX())};
        double yDiff{abs(p->getY() - p2->getY())};
        double diffSum = xDiff + yDiff;
        fitnessSum += diffSum;
    }
    cout << fitnessSum << endl;
}
