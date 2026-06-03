#include "include/algorithms/dijkstra.h"
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>

PathResult dijkstra(const Graph& graph, int source, int target) {
    const double INF = std::numeric_limits<double>::infinity();

    std::unordered_map<int, double> dist;
    std::unordered_map<int, int>    prev;

    for (const auto& [id, _] : graph.nodes) {
        dist[id] = INF;
        prev[id] = -1;
    }
    dist[source] = 0;

    using PQEntry = std::pair<double, int>;
    std::priority_queue<PQEntry, std::vector<PQEntry>, std::greater<PQEntry>> pq;
    pq.push({0.0, source});

    // BFS
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (u == target) break;
        if (cost > dist[u]) continue;

        for (const Edge& e: graph.adjacency.at(u)) {
            double new_dist = dist[u] + e.weight;
            if (new_dist < dist[e.to]) {
                dist[e.to] = new_dist;
                prev[e.to] = u;
                pq.push({new_dist, e.to});
            }
        }
    }

    if (dist[target] == INF) return {INF, {}, false};

    std::vector<int> path;
    for (int v = target; v != -1; v = prev[v])
        path.push_back(v);
    std::reverse(path.begin(), path.end());

    return {dist[target], path, true};
}