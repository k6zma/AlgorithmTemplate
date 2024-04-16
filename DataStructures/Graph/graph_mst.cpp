#include <vector>
#include <queue>

class DSU {
private:
    std::vector<int> p;
    std::vector<int> r;

public:
    DSU(int count_of_vertices) {
        p.resize(count_of_vertices + 1);
        r.resize(count_of_vertices + 1, 0);
        for (int i = 0; i <= count_of_vertices; i++) {
            p[i] = i;
        }
    }

    int collect_root(int v) {
        if (p[v] == v) {
            return v;
        }

        return p[v] = collect_root(p[v]);
    }

    void merge(int v1, int v2) {
        v1 = collect_root(v1);
        v2 = collect_root(v2);

        if (v1 != v2) {
            if (r[v1] < r[v2]) {
                std::swap(v1, v2);
            }

            p[v2] = v1;

            if (r[v1] == r[v2]) {
                r[v1]++;
            }
        }
    }
};

class Graph {
private:
    std::vector<std::pair<int, std::pair<int,int>>> graph_edges;
    std::vector<std::vector<int>> graph_adj_matrix;

    int count_of_vertices;
    int count_of_edges;

    int kruskal() {
        int cost = 0;

        sort(graph.begin(), graph.end());
        DSU dsu(count_of_vertices);

        for (int i = 0; i < count_of_edges; i++) {
            int v1 = graph[i].second.first;
            int v2 = graph[i].second.second;
            int w = graph[i].first;

            if (dsu.collect_root(v1) != dsu.collect_root(v2)) {
                cost += w;
                dsu.merge(v1, v2);
            }
        }

        return cost;
    }

    int prim() {
        int mst_weight = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        std::vector<bool> used(count_of_vertices, false);

        q.push({0, 0});

        while (!q.empty()) {
            std::pair<int,int> c = q.top();
            q.pop();

            int dst = c.first, v = c.second;

            if (used[v]) {
                continue;
            }

            used[v] = true;
            mst_weight += dst;

            for (int u = 0; u < count_of_vertices; u++) {
                if (graph_adj_matrix[v][u] != 0 && !used[u]) {
                    q.push({graph_adj_matrix[v][u], u});
                }
            }
        }

        return mst_weight;
    }

public:
    Graph(int count_of_vertices, int count_of_edges) : count_of_vertices(count_of_vertices), count_of_edges(count_of_edges) {
        graph_adj_matrix.resize(count_of_vertices, std::vector<int>(count_of_vertices, 0));
    }

    void add_edge(int v1, int v2, int w) {
        graph.push_back({w, {v1, v2}});

        graph_adj_matrix[v1][v2] = w;
        graph_adj_matrix[v2][v1] = w;
    }
};