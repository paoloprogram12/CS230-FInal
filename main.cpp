#include <iostream>
using namespace std;

class Vertex {
private:
    int num;
    string name;

public:
    Vertex(int num, string name) : num(num), name(name) {}
};

class Edge {
private:
    int source;
    int destination;
    int weight;

public:
    Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight) {}

    // compare weight with other weight
    bool operator<(const Edge& other) const { return this->weight < other.weight; }
};

int main() {


    return 0;
}
