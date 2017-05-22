#ifndef PRIORITYZONE_H
#define PRIORITYZONE_H

#include <sstream>

using namespace std;

class PriorityZone {

    protected:
        double availableVolume;
        double topLimit;
        int priority;

    public:
        PriorityZone();
        PriorityZone(double availableVolume, int priority);
        PriorityZone(double availableVolume, double topLimit, int priority);

        double getAvailableVolume();
        double getTopLimit();
        int getPriority();

        void setPriority(int priority);

        string toString();

};

#endif // PRIORITYZONE_H
