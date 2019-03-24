//
// Created by curti on 2019-03-21.
//

#include "Population.hpp"


void Population::addToPopulation(Tour tour) {
    populationList.push_back(tour);
}

void Population::printPopulation() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        cout << populationList[i].getID() << " " << populationList[i].getFitnessRating() << endl;
    }
}

void Population::shuffleTours() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        populationList[i].loadPtrs();
        populationList[i].shuffle();
        populationList[i].calcFitness();
    }
}

void Population::algorithm() {
    static std::default_random_engine generator2( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution2(1, 25);
    shiftElite();
    vector<Tour> crosses;

    int index1 = distribution2(generator2);
    int index2 = distribution2(generator2);

    crosses.push_back(populationList[0]);

    for (int i = 0; i < POPULATION_SIZE - 1; ++i) {
        Tour parent1 = chooseCandidate(index1);
        Tour parent2 = chooseCandidate(index2);
        Tour child = breed(parent1, parent2);
        crosses.push_back(child);
    }

//    vector<Tour>::iterator it1;
//    vector<Tour>::iterator it2;
//    for (it1 = populationList.begin() + 1, it2 = crosses.begin(); it2 != crosses.end()/*it1 != populationList.end()*/; ++it1, ++it2) {
//        populationList.insert(it1, it2, it2);
//    }

    populationList = crosses;

    //printPopulation();
    cout << endl;
    //mutate();

}

void Population::shiftElite() {
    Tour elite = populationList[0];
    int eliteIndex = 0;
    double minFitness = elite.getFitnessRating();
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        if(populationList[i].getFitnessRating() < minFitness) {
            elite = populationList[i];
            minFitness = populationList[i].getFitnessRating();
            eliteIndex = i;
        }
    }
    swap(populationList[0], populationList[eliteIndex]);
}

Tour Population::breed(Tour &t1, Tour &t2) {
    Tour child;

    static std::default_random_engine generator2( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution2(0, 31);


    int index = distribution2(generator2);
    int counter = index;

    for (int i = 0; i < index; ++i) {
        child.addToTour(t1.getCity(i));
    }

    for (int j = 0; j < 32; ++j) {
        if(!(mergeConflict(child.getMasterList(), t2.getCity(j)))){
            child.addToBackOfTour(t2.getCity(j), counter++);
        }
    }
    child.loadPtrs();
    child.shuffle();
    child.calcFitness();
    return child;

}


bool Population::mergeConflict(vector<City> vec, City& city) {
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i].getName() == city.getName())
            return true;
    }
    return false;
}

Tour Population::chooseCandidate(int n) {
    vector<Tour> candidates;
    for (int i = n; i < n+5; ++i) {
        candidates.push_back(populationList[i]);
    }
    Tour bestFit = candidates[0];
    double bestFitness = candidates[0].getFitnessRating();
    for (int j = 0; j < candidates.size(); ++j) {
        if(candidates[j].getFitnessRating() < bestFitness){
            bestFit = candidates[j];
            bestFitness = candidates[j].getFitnessRating();
        }
    }
    return bestFit;
}

void Population::mutate(Tour& tour) {
    static std::default_random_engine generator2( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution2(1, 100);

    tour.printTour();
    cout << endl;
    for(int i = 0, j = 1; i < CITIES_IN_TOUR; i++, j++){
        int mutationRate = distribution2(generator2);
        if(mutationRate < MUTATION_RATE){
            std::swap(tour.getCity(i), tour.getCity(j));
        }

    }

    tour.printTour();
}
