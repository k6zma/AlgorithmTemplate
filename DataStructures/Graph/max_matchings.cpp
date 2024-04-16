#include <vector>
#include <queue>

class Graph {
private:
    int n, m;
    std::vector<std::vector<int>> graph;
    std::vector<int> used;
    std::vector<int> matching;
    std::vector<int> px, py;

    bool dfs(int v) {
        used[v] = true;
        for (int to : graph[v]) {
            if (matching[to] == -1 || (!used[matching[to]] && dfs(matching[to]))) {
                matching[to] = v;

                return true;
            }
        }

        return false;
    }

    bool dfsFordFulkerson(int x) {
        if (used[x]) {
            return false;
        }

        used[x] = true;
        for (int y : graph[x]) {
            if (py[y] == -1 || dfsFordFulkerson(py[y])) {
                py[y] = x;
                px[x] = y;
                return true;
            }
        }
        return false;
    }

public:
    Graph(int n, int m) : n(n), m(m){
        graph.resize(n * m);
        used.resize(n * m, false);
        matching.resize(n * m, -1);
        px.resize(n * m, -1);
        py.resize(n * m, -1);
    }

    void add_edge(int v1, int v2) {
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int kun() {
        int result = 0;
        for (int i = 0; i < graph.size(); i++) {
            fill(used.begin(), used.end(), false);

            if (dfs(i)) {
                result++;
            }
        }

        return result;
    }

    int fordFulkerson() {
        int result = 0;
        bool isPath;
        do {
            isPath = false;
            std::fill(used.begin(), used.end(), false);
            for (int x = 0; x < n; ++x) {
                if (px[x] == -1 && dfsFordFulkerson(x)) {
                    isPath = true;
                    result++;
                }
            }
        } while (isPath);
        return result;
    }
};