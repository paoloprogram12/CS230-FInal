#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"
using namespace std;

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


    // graph declaration
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    vector<Edge> MST = g.kruskals();

    int totalWeight = 0;
    cout << "Edges in MST:" << endl;
    for (const Edge& e : MST) {
        cout << e.getSource() << " -- " << e.getDestination() << " == " << e.getWeight() << endl;
        totalWeight += e.getWeight();
    }
    cout << "Total Weight: " << totalWeight << endl;

    return 0;
}
