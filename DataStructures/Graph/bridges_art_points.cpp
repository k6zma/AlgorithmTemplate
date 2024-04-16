#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> graph;
    std::vector<bool> visited;
    std::vector<int> tin, low;
    std::vector<int> articulationPoints;
    std::vector<std::pair<int, int>> bridges;
    int V;
    int timer;

    void dfsArticulationPoints(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        int children = 0;

        for (int to : graph[v]) {
            if (to == p) {
                continue;
            }

            if (visited[to]) {
                low[v] = std::min(low[v], tin[to]);
            } else {
                dfsArticulationPoints(to, v);
                low[v] = std::min(low[v], low[to]);
                if ((p != -1 && low[to] >= tin[v]) || (p == -1 && children > 1)) {
                    articulationPoints.push_back(v);
                }
                ++children;
            }
        }
    }

    void dfsBridges(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;

        for (int to : graph[v]) {
            if (to == p) {
                continue;
            }

            if (visited[to]) {
                low[v] = std::min(low[v], tin[to]);
            } else {
                dfsBridges(to, v);
                low[v] = std::min(low[v], low[to]);
                if (low[to] > tin[v]) {
                    bridges.push_back({v, to});
                }
            }
        }
    }

public:
    Graph(int count_of_verticies) : V(count_of_verticies), timer(0) {
        graph.resize(V);
        visited.resize(V, false);
        tin.resize(V, -1);
        low.resize(V, -1);
    }

    void add_edge(int v1, int v2) {
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    std::vector<int> findArticulationPoints() {
        std::fill(visited.begin(), visited.end(), false);
        std::fill(tin.begin(), tin.end(), -1);
        std::fill(low.begin(), low.end(), -1);
        articulationPoints.clear();

        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfsArticulationPoints(i);
        }
        return articulationPoints;
    }

    std::vector<std::pair<int, int>> findBridges() {
        std::fill(visited.begin(), visited.end(), false);
        std::fill(tin.begin(), tin.end(), -1);
        std::fill(low.begin(), low.end(), -1);
        bridges.clear();

        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfsBridges(i);
        }
        return bridges;
    }
};