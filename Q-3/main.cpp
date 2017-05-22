#include <iostream>

#include "node.h"

using namespace std;

void runDelivery(Node * n, int * step) {
    bool stop = false;
    while(!stop) {

        stop = true;
        (*step) = (*step) + 1;

        cout << "Passo " << (*step) << endl;
        cout << "=======" << endl;

        cout << n->name << "(" << *(step) << ") = " << n->value << endl;
        for(auto i: n->nexts) {
            double toGive = i->value;

            if(toGive > n->value) {
                cout << n->name << " não consegue mais liberar para " << i->name << endl;
            } else {
                stop = false;
                cout << n->name << " libera " << i->value << " para " << i->name << endl;

                n->value -= toGive;
                if(i->nexts.size() > 0) {
                    runDelivery(i, step);
                    i->value += toGive;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {

    Node * f = new Node(0, 10, "F");
    Node * c1 = new Node(0, 3, "C1");

    f->addNext(c1);

    int * step = new int;
    (*step) = 0;
    runDelivery(f, step);

    return 0;
}
