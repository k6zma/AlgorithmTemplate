#include <vector>
#include <queue>

class Graph {
private:
    std::vector<std::pair<int, std::pair<int,int>>> graph_edges;
    std::vector<std::vector<int>> graph_adj_matrix;
    int num_vertices;

public:
    Graph(int count_of_vertices) : num_vertices(count_of_vertices) {
        graph_adj_matrix.resize(count_of_vertices, std::vector<int>(count_of_vertices, 0));
    }

    void add_edge(int v1, int v2, int weight) {
        graph_edges.push_back({weight, {v1, v2}});

        graph_adj_matrix[v1][v2] = weight;
        graph_adj_matrix[v2][v1] = weight;
    }

    std::vector<int> dijkstra(int v) {
        std::vector<int> distance(num_vertices, INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        distance[v] = 0;
        pq.push({0, v});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int current_vertex = pq.top().second;
            pq.pop();

            if (dist > distance[current_vertex]) {
                continue;
            }

            for (int i = 0; i < num_vertices; ++i) {
                if (graph_adj_matrix[current_vertex][i] != 0) {
                    int weight = graph_adj_matrix[current_vertex][i];
                    if (distance[current_vertex] + weight < distance[i]) {
                        distance[i] = distance[current_vertex] + weight;
                        pq.push({distance[i], i});
                    }
                }
            }
        }

        return distance;
    }

    bool fordBellman(int s) {
        std::vector<int> d(num_vertices, INT_MAX);
        d[s] = 0;

        for (int i = 0; i < num_vertices; ++i) {
            for (auto edge : graph_edges) {
                int u = edge.second.first;
                int v = edge.second.second;
                int weight = edge.first;

                if (d[u] < INT_MAX && d[v] > d[u] + weight) {
                    d[v] = d[u] + weight;
                }
            }
        }

        for (auto edge : graph_edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;

            if (d[u] < INT_MAX && d[v] > d[u] + weight) {
                return false;
            }
        }

        return true;
    }


    std::vector<std::vector<int>> floydWarshall() {
        std::vector<std::vector<int>> dist_matrix;

        for (int k = 0; k < num_vertices; ++k) {
            for (int i = 0; i < num_vertices; ++i) {
                for (int j = 0; j < num_vertices; ++j) {
                    if (dist_matrix[i][k] != INT_MAX && dist_matrix[k][j] != INT_MAX) {
                        dist_matrix[i][j] = std::min(dist_matrix[i][j], dist_matrix[i][k] + dist_matrix[k][j]);
                    }
                }
            }
        }

        return dist_matrix;
    }
};