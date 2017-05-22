#include "priorityzone.h"

PriorityZone::PriorityZone() {}

PriorityZone::PriorityZone(double availableVolume, int priority)
    : availableVolume(availableVolume), priority(priority) {}

PriorityZone::PriorityZone(double availableVolume, double topLimit, int priority)
    : availableVolume(availableVolume), topLimit(topLimit),priority(priority) {}

double PriorityZone::getAvailableVolume() {
    return availableVolume;
}

double PriorityZone::getTopLimit() {
    return topLimit;
}

int PriorityZone::getPriority() {
    return priority;
}

void PriorityZone::setPriority(int priority) {
    this->priority = priority;
}

string PriorityZone::toString() {
    stringstream ss;
    ss << "PriorityZone(" << this->priority << ", " << this->availableVolume << ")";
    return ss.str();
}

