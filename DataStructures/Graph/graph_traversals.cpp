#include <vector>
#include <queue>

class Graph {
private:
    std::vector<std::vector<int>> graph;
    std::vector<bool> visited;
    std::vector<int> top_sort_order;

public:
    Graph(int count_vertices) {
        graph.resize(count_vertices);
        visited.resize(count_vertices, false);
    }

    void add_edge(int v1, int v2) {
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    void dfs(int v) {
        visited[v] = true;

        for (int u : graph[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
    }

    void bfs(int v) {
        std::queue<int> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty()) {
            int current_vertex = q.front();
            q.pop();

            for (int u : graph[current_vertex]) {
                if (!visited[u]) {
                    q.push(u);
                    visited[u] = true;
                }
            }
        }
    }

    void top_sort(int v) {
        visited[v] = true;

        for (int u : graph[v]) {
            if (!visited[u]) {
                top_sort(u);
            }
        }

        top_sort_order.push_back(v);
    }
};