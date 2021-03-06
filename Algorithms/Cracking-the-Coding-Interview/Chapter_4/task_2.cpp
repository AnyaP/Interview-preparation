#include <queue>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "../../testing.h"

using Graph = std::vector< std::vector<int> >;

std::random_device rd;
std::mt19937 gen(rd());


bool FindRoute(const Graph& graph, int nodesNumber, int from, int to) {
    if (from == to) {
        return true;
    }

    std::queue<int> toBeProcessed;
    std::vector<bool> reached(nodesNumber, false);
    toBeProcessed.push(from);
    reached[from] = true;

    while (!toBeProcessed.empty()) {
        int node = toBeProcessed.front();
        toBeProcessed.pop();
        for (int next  : graph[node]) {
            if (!reached[next]) {
                if (next == to) {
                    return true;
                } else {
                    reached[next] = true;
                    toBeProcessed.push(next);
                }
            }
        }
    }
    return false;
}


void GenerateRandomEdges(Graph* g, int minNode, int maxNode, int requiredEdgesNumber) {
    int generatedEdgesNumber = 0;
    while (generatedEdgesNumber < requiredEdgesNumber) {
        // generate a random edge
        std::uniform_int_distribution<> dis(minNode, maxNode);
        int from = dis(gen);
        int to = dis(gen);
        // add it if it doesn't exist yet
        std::vector<int>& edges = (*g)[from];
        bool edgeFound = std::find(edges.begin(), edges.end(), to) != edges.end();
        if (!edgeFound) {
            edges.push_back(to);
            ++generatedEdgesNumber;
        }
    }
}

void TestFindRoute() {
    // one point
    int n = 1;
    Graph g(n);
    CHECK_EQUAL(FindRoute(g, n, 0, 0), true);

    // two isolated points
    n = 2;
    g.resize(n);
    CHECK_EQUAL(FindRoute(g, n, 0, 1), false);

    // one direction linked points
    g[0] = {1};
    CHECK_EQUAL(FindRoute(g, n, 0, 1), true);
    CHECK_EQUAL(FindRoute(g, n, 1, 0), false);

    // more points
    n = 5;
    g.assign({{}, {2,3}, {1,4}, {}, {3}});
    CHECK_EQUAL(FindRoute(g, n, 1, 4), true);
    CHECK_EQUAL(FindRoute(g, n, 4, 1), false);

    // two components
    n = 40;
    g.assign(n, {});
    GenerateRandomEdges(&g, 0,  19, 200);
    GenerateRandomEdges(&g, 20, 39, 200);

    std::uniform_int_distribution<> firstComponent(0 , 19);
    std::uniform_int_distribution<> secondComponent(20 , 39);

    for (int i = 0; i < 100; ++i) {
        int from = firstComponent(gen);
        int to = secondComponent(gen);
        CHECK_EQUAL(FindRoute(g, n, from, to), false);
    }
}


int main() {
    TestFindRoute();
    std::cout << "Hello world";
    return 0;
}


