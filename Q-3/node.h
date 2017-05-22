#ifndef NODE_H
#define NODE_H

#include <sstream>
#include <vector>

using namespace std;

class Node {

    public:
        int id;
        double value;
        vector<Node*> nexts;
        string name;

        Node(int id, double value) : id(id), value(value) {}
        Node(int id, double value, string name) : id(id), value(value), name(name) {}

        void addNext(Node * n) {
            this->nexts.push_back(n);
        }

};

#endif // NODE_H
