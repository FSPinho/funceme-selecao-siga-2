#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <vector>
#include <algorithm>

#include "priorityzone.h"
#include "priorityutils.h"

class Reservoir {
    private:
        double initialValue;
        double minimumValue;
        double maximumValue;
        vector<PriorityZone> priorityZones;

    public:
        Reservoir(double initialValue, double minimumValue, double maximumValue);

        double getInitialValue();
        double getMinimumValue();
        double getMaximumValue();
        vector<PriorityZone> getPriorityZones();

        void addPriorityZone(PriorityZone p);
        void removePriorityZone(PriorityZone p);
};

#endif // RESERVOIR_H
