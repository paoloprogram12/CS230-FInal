#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"
using namespace std;

void Graph::addEdge(int u, int v, int w) {
    edges.emplace_back(u, v, w);
}

int Graph::find(int x, vector<int>& p) {
    if (p[x] == x) { return x; }

    return p[x] = find(p[x], p);
}

void Graph::unionSet(int u, int v, vector<int>& p, vector<int>& r) {
    // used to figure out which group is u and v in
    int rootU = find(u, p);
    int rootV = find(v, p);

    // goal is to compare ranks to keep the parents shallow
    // if the depth of rank[u] is less than rank[v], assigns v to the parent of u
    if (r[rootU] < r[rootV]) { p[rootU] = rootV; }
    // if the depth of rank[v] is less than rank[u], assigns u to the parent of v
    else if (r[rootU] > r[rootV]) { p[rootV] = rootU; }
    // if their ranks are equal, assigns either one to each other and increments the ranks by 1
    else { 
        p[rootV] = rootU;
        r[rootU]++;
    }

    
}

vector<Edge> Graph::kruskals() {

    // sort the graph by weight, operator < helps with STL sort
    sort(edges.begin(), edges.end());

    // goal: group vertices, each vertex is its own group, and as we add edges
    // we connect vertices into larger groups
    // if two vertices are in the same group, it means they're already connected in the MST
    // used to prevent cycles
    // knows when its safe to connect two dots
    // parent vector: used to find which group the vertex belongs to (leader)
    vector<int> parent(vertices);

    // rank vector: used to figure out which group will become the parent when merging the vectors
    // assigns the depth to 0 for each vertex
    vector<int> rank(vertices, 0);

    // assigns vertices into parent
    for (int i = 0; i < vertices; i++) { parent[i] = i; }

    // holds the MST
    int totalWeight = 0;
    vector<Edge> MST;
    for (const Edge& e : edges) {
        int u = e.getSource();
        int vtx = e.getDestination();
        int w = e.getWeight();

        // if u and v are in different sets, then add to MST
        if (find(u, parent) != find(vtx, parent)) {
            MST.push_back(e);
            unionSet(u, vtx, parent, rank); // merge the two groups
            totalWeight += w;
        }
    }
    return MST;
}