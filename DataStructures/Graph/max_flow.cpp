#include <vector>
#include <queue>

class Graph {
private:
    int n, m;
    std::vector<std::vector<int>> graph;
    std::vector<int> parent;
    std::vector<std::vector<int>> capacity;

    int bfs(int s, int t) {
        std::fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;

        std::queue<std::pair<int, int>> q;
        q.push({s, INT_MAX});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : graph[cur]) {
                if (parent[next] == -1 && capacity[cur][next]) {
                    parent[next] = cur;

                    int new_flow = std::min(flow, capacity[cur][next]);
                    if (next == t) {
                        return new_flow;
                    }

                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }

public:
    Graph(int n, int m) : n(n), m(m){
        graph.resize(n + 1);
        capacity.resize(n + 1, std::vector<int>(n + 1, 0));
        parent.resize(n + 1);
    }

    void add_edge(int v1, int v2, int c) {
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        capacity[v1][v2] = c;
    }

    int max_flow_edmons_karp(int s, int t) {
        int flow = 0;
        int new_flow;

        while ((new_flow = bfs(s, t)) != 0) {
            flow += new_flow;

            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};