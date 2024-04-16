#include <iostream>
#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> transposed_graph;
    std::vector<bool> visited;
    std::vector<int> order;
    std::vector<int> component;
    std::vector<int> componentsCount;

public:
    Graph(int count_vertices) {
        graph.resize(count_vertices);
        transposed_graph.resize(count_vertices);
        visited.resize(count_vertices, false);
        componentsCount.resize(count_vertices, 0);
    }

    void add_edge(int v1, int v2) {
        graph[v1].push_back(v2);
        transposed_graph[v2].push_back(v1);
    }

    void dfs(int v, int num) {
        componentsCount[v] = num;
        visited[v] = true;
        for (int u : graph[v]) {
            if (!visited[u]) {
                dfs(u, num);
            }
        }
    }

    void dfs1(int v) {
        visited[v] = true;
        for (int to : graph[v]) {
            if (!visited[to]) {
                dfs1(to);
            }
        }
        order.push_back(v);
    }

    void dfs2(int v) {
        visited[v] = true;
        component.push_back(v);
        for (int to : transposed_graph[v]) {
            if (!visited[to]) {
                dfs2(to);
            }
        }
    }

    std::vector<std::vector<int>> findStrongComponents() {
        std::fill(visited.begin(), visited.end(), false);
        order.clear();

        for (int i = 0; i < graph.size(); ++i) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        std::fill(visited.begin(), visited.end(), false);
        std::reverse(order.begin(), order.end());
        std::vector<std::vector<int>> result;

        for (int v : order) {
            if (!visited[v]) {
                component.clear();
                dfs2(v);
                result.push_back(component);
            }
        }

        return result;
    }
};