#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

void kruskals(vector<Edge>&, int);

int main() {


    // graph declaration
    vector<Edge> edges; 
    int numVertices = 5; // vertices: 0, 1, 2, 3, 4
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));
    edges.push_back(Edge(1, 2, 7));
    edges.push_back(Edge(2, 4, 9));
    edges.push_back(Edge(3, 4, 8));
    edges.push_back(Edge(1, 4, 11));
    edges.push_back(Edge(0, 4, 14));

    kruskals(edges, numVertices);



    return 0;
}

void kruskals(vector<Edge>& g, int v) {

    // sort the graph by weight, operator < helps with STL sort
    sort(g.begin(), g.end());

    // goal: group vertices, each vertex is its own group, and as we add edges
    // we connect vertices into larger groups
    // if two vertices are in the same group, it means they're already connected in the MST
    // used to prevent cycles
    // knows when its safe to connect two dots
    // parent vector: used to find which group the vertex belongs to (leader)

    vector<int> parent;
    // rank vector: used to figure out which group will become the parent when merging the vectors
    vector<int> rank;

    for (int i = 0; i < v ; i++) {
        // assigns vertices into parent
        parent[i] = i;
        // assigns the depth to 0 for each vertex
        rank[i] = 0;
    }

    // 
}
