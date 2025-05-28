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

    int getSource() const { return source; }
    int getDestination() const { return destination; }
    int getWeight() const { return weight; }

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
int find(int, vector<int>&);
void unionSet(int, int, vector<int>&, vector<int>&);

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
    vector<int> parent(v);

    // rank vector: used to figure out which group will become the parent when merging the vectors
    // assigns the depth to 0 for each vertex
    vector<int> rank(v, 0);

    // assigns vertices into parent
    for (int i = 0; i < v ; i++) { parent[i] = i; }

    // holds the MST
    int totalWeight = 0;
    vector<Edge> MST;
    for (Edge e : g) {
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

    cout << "Edges in MST:" << endl;
    for (Edge e : MST) {
        cout << e.getSource() << " -- " << e.getDestination() << " == " << e.getWeight() << endl;
    }
    cout << "Total Weight: " << totalWeight << endl;

}

// find is used to figure out what group does the vertex belong to
int find(int x, vector<int>& p) {
    if (p[x] == x) { return x; }

    return p[x] = find(p[x], p);
}

// merge the groups that contain two vertices, u, and v
// done after we've checked using the find fuction that u and v are in different groups
// u is the source
// v is the destination
void unionSet(int u, int v, vector<int>& p, vector<int>& r) {
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
