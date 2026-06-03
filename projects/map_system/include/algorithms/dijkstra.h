#pragma once
#include <vector>
#include "graph/graph.h"

struct PathResult {
    double           distance;
    std::vector<int> path;
    bool             found;
};

// Free function
PathResult dijkstra(const Graph& graph, int source, int target);