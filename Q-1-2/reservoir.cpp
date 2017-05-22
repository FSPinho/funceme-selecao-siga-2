#include "reservoir.h"

Reservoir::Reservoir(double initialValue, double minimumValue, double maximumValue)
    : initialValue(initialValue), minimumValue(minimumValue), maximumValue(maximumValue) {}

double Reservoir::getInitialValue() {
    return this->initialValue;
}

double Reservoir::getMinimumValue() {
    return this->minimumValue;
}

double Reservoir::getMaximumValue() {
    return this->maximumValue;
}

vector<PriorityZone> Reservoir::getPriorityZones() {
    return this->priorityZones;
}

void Reservoir::addPriorityZone(PriorityZone p) {
    double topLimit = p.getTopLimit();
    this->priorityZones.push_back(*(new PriorityZone(0.0, topLimit, 0)));

    sort(this->priorityZones.begin(), this->priorityZones.end(), [](PriorityZone a, PriorityZone b) -> bool {
        return a.getTopLimit() < b.getTopLimit();
    });

    int priority = 1;
    for(auto &i: this->priorityZones) {
        i.setPriority(priority++);
    }

    vector<int> pArray;
    vector<double> vArray;

    for(auto i: this->priorityZones) {
        pArray.push_back(i.getPriority());
        vArray.push_back(i.getTopLimit());
    }

    this->priorityZones.clear();
    this->priorityZones = PriorityUtils::zonesAvailableSupply(pArray, vArray, this->minimumValue, this->maximumValue, this->initialValue);
}

void Reservoir::removePriorityZone(PriorityZone p) {
    double topLimit = p.getTopLimit();

    vector<int> pArray;
    vector<double> vArray;

    for(auto i: this->priorityZones) {
        if(i.getTopLimit() != topLimit) {
            pArray.push_back(i.getPriority());
            vArray.push_back(i.getTopLimit());
        }
    }

    this->priorityZones.clear();
    this->priorityZones = PriorityUtils::zonesAvailableSupply(pArray, vArray, this->minimumValue, this->maximumValue, this->initialValue);
}


