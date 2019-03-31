//
// Created by curti on 2019-03-21.
//

#include "Population.hpp"

void Population::addToPopulation(Tour tour) {
    populationList.push_back(tour);
}

void Population::printPopulation() {
    for (int i = 0; i < populationList.size(); ++i) {
        cout << populationList[i].getID() << " " << populationList[i].getFitnessRating() << endl;
    }
}

void Population::shuffleTours() {
    for (int i = 0; i < populationList.size(); ++i) {
        populationList[i].shuffle();
        populationList[i].calcFitness();
    }
}

void Population::algorithm() {
    static std::default_random_engine generator2( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution2(1, 25);

    static std::default_random_engine generator3( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution3(1, 100);

    cout << "Original population: " << endl;
    printPopulation();
    shiftElite();
    vector<Tour> crosses;

    cout << endl << endl;

    cout << "First elite shifted: " << endl;
    printPopulation();

    cout << endl << endl;

    Tour elite = calcBestFit();

    cout << "Elite tour ID: " << elite.getID() << endl << "Fitness Rating: " << elite.getFitnessRating() << endl;

    cout << endl << endl;

    cout << "Population before breed: " << endl;
    printPopulation();
    cout << endl << endl;

    for (int i = 0; i < POPULATION_SIZE - 1; ++i) {
        int index1 = distribution2(generator2);
        int index2 = distribution2(generator2);
        Tour parent1 = chooseCandidate(index1);
        Tour parent2 = chooseCandidate(index2);
        Tour child = breed(parent1, parent2);
        crosses.push_back(child);
    }


    for (int k = 0; k < crosses.size(); ++k) {
        crosses[k].shuffle();
        crosses[k].calcFitness();
    }

    populationList.clear();
    populationList.push_back(elite);
    for (int l = 0; l < crosses.size(); ++l) {
        populationList.push_back(crosses[l]);
    }

    cout << "Population after breed: " << endl;
    printPopulation();
    cout << endl;
    cout << endl;

    // each tour has a 40% chance of mutating
    int mutationChance = 40;
    int counter = 0;

    for (int j = 1; j < populationList.size(); ++j) {
        int mutation = distribution3(generator3);
        if(mutation < mutationChance){
            counter++;
            mutate(populationList[j]);
            populationList[j].calcFitness();
        }
    }

    cout << "Pop after mutation: " << endl;
    printPopulation();
    cout << endl;
    cout << endl;

    for (int m = 1; m < populationList.size(); ++m) {
        populationList[m].calcFitness();
    }


    cout << "Pop after mutation after fitness calculated: " << endl;
    printPopulation();
    cout << endl;
    cout << endl;

    cout << "Number of mutations: " << counter << endl;
    cout << endl << endl;

    shiftElite();

    cout << endl;
    cout << "Pop after mutation and elite shifted again: " << endl;
    printPopulation();
    cout << endl;
    cout << endl;
    crosses.clear();

}

void Population::shiftElite() {
    Tour elite = calcBestFit();
    int index = getIndex(elite);
    iter_swap(populationList.begin(), populationList.begin() + index);
}


Tour Population::breed(Tour &t1, Tour &t2) {
    Tour child;
    vector<City> temp;

    static std::default_random_engine generator2( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution2(0, 31);


    int index = distribution2(generator2);

    for (int i = 0; i < index; ++i) {
        temp.push_back(t1.getCity(i));
    }

    for (int j = 0; j < 32; ++j) {
        if(!(mergeConflict(temp, t2.getCity(j)))){
            temp.push_back(t2.getCity(j));
        }
    }

    child.setMasterList(temp);
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

void Population::mutate(Tour tour) {
    static std::default_random_engine generator2( std::random_device{}() );
    static std::uniform_int_distribution<int> distribution2(1, 100);

    for(int i = 0, j = 1; j < CITIES_IN_TOUR; i++, j++){
        int mutationRate = distribution2(generator2);
        if(mutationRate < MUTATION_RATE){
            std::swap(tour.getCity(i), tour.getCity(j));
        }
    }



}

Tour Population::calcBestFit() {
    Tour bestFit = populationList[0];
    double bestFitness = populationList[0].getFitnessRating();
    for (int i = 0; i < populationList.size(); ++i) {
        if(populationList[i].getFitnessRating() > bestFitness){
            bestFit = populationList[i];
            bestFitness = populationList[i].getFitnessRating();
        }
    }
    return bestFit;
}

int Population::getIndex(Tour tour) {
    int index = 0;
    for (int i = 0; i < populationList.size(); ++i) {
        if(tour.getID() == populationList[i].getID())
            index = i;
    }
    return index;
}
