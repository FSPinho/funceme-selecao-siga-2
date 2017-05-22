#ifndef PRIORITYUTILS_H
#define PRIORITYUTILS_H

#include <vector>
#include <algorithm>

#include "priorityzone.h"

using namespace std;
using VectorOfPriorityZones = vector<PriorityZone>;

class PriorityUtils {

    public:
        /** @brief
         * Retorna o volume de água disponível em cada zona de prioridade
         * @param pArray é um vetor contendo as prioridades de cada zona
         * @param vArray é o limite superior de cada zona
         * @param minimumVolume é o volume mínimo do reservatório
         * @param maximumVolume é o volume máximo do reservatório
         * @param currentVolume é o volume atual do reservatório
         **/
        static VectorOfPriorityZones zonesAvailableSupply(
                vector<int> pArray,
                vector<double> vArray,
                double minimumVolume,
                double maximumVolume,
                double currentVolume)
        {

            vector<PriorityZone> zones;

            for(int i = 0; i < pArray.size(); i++) {
                zones.push_back(PriorityZone(0.0, vArray[i], pArray[i])); // available, topLimit, priority
            }

            sort(zones.begin(), zones.end(), [](PriorityZone a, PriorityZone b) -> bool {
                return a.getPriority() < b.getPriority();
            });

            vector<PriorityZone> pzArray;

            double lastBottomLimit = minimumVolume;
            for(auto i: zones) {
                double top = i.getTopLimit() < currentVolume ? i.getTopLimit() : currentVolume;
                PriorityZone * p = new PriorityZone(top - lastBottomLimit, i.getTopLimit(), i.getPriority());
                pzArray.push_back(*p);
                lastBottomLimit = top;
            }

            return pzArray;
        }

};

#endif // PRIORITYUTILS_H
