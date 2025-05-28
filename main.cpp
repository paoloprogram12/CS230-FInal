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

//kruskal's algorithm is an algorithm that is used to find the minimum spanning tree of a graph.
// how it works:
// sorts all the edges in non-decreasing order by weight
// initalize a set of trees where each vertex is its own separate tree
// go through each edge in sorted order, if the edge connects two different trees, then it adds it to the MST

// Minimum Spanning Tree (MST)
// connects all vertices so there are no isolated nodes
// has no cycles
// has the minimum possible total edge weight

int main() {


    return 0;
}
