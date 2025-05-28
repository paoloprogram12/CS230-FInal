#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
using namespace std;

class Edge {
private:
    int source;
    int destination;
    int weight;

public:
    Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight) {}

    int getSource() const { return source; }
    int getDestination() const { return destination; }
    int getWeight() const { return weight; }

    // compare weight with other weight
    bool operator<(const Edge& other) const { return this->weight < other.weight; }
};

class Graph {
private: 
    int vertices;
    vector<Edge> edges;

    int find(int x, vector<int>& p);
    void unionSet(int u, int v, vector<int>& p, vector<int>& r);

public:
    Graph(int vertex) : vertices(vertex) {}
    void addEdge(int u, int v, double w);
    vector<Edge> findMST();
};

#endif