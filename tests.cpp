#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "graph.cpp"

TEST_CASE("MST - Kruskal's Algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 1.0);
    g.addEdge(0, 2, 3.0);
    g.addEdge(0, 3, 4.0);
    g.addEdge(1, 2, 2.0);
    g.addEdge(2, 3, 5.0);

    auto result = g.kruskals();

    int totalWeight = 0;
    for (const Edge& e : result) {
        totalWeight += e.getWeight();
    }

    REQUIRE(result.size() == 3);
    REQUIRE(totalWeight == Approx(7)); // Expected MST total weight: 1 + 2 + 4 = 7
}