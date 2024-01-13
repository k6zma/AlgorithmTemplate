#include <string>
#include <vector>
#include <iostream>

std::pair<int, std::string> levensteinInstruction(std::string s1, std::string s2, int InsertCost, int DeleteCost, int ReplaceCost) {
    int M = s1.size();
    int N = s2.size();
    std::vector<std::vector<int>> D(M + 1, std::vector<int>(N + 1));
    std::vector<std::vector<std::string>> changes(M + 1, std::vector<std::string>(N + 1));

    D[0][0] = 0;
    for (int j = 1; j <= N; ++j) {
        D[0][j] = D[0][j - 1] + InsertCost;
        changes[0][j] = "Insert " + std::string(1, s2[j - 1]);
    }
    for (int i = 1; i <= M; ++i) {
        D[i][0] = D[i - 1][0] + DeleteCost;
        changes[i][0] = "Delete " + std::string(1, s1[i - 1]);
        for (int j = 1; j <= N; ++j) {
            if (s1[i - 1] != s2[j - 1]) {
                int deleteCost = D[i - 1][j] + DeleteCost;
                int insertCost = D[i][j - 1] + InsertCost;
                int replaceCost = D[i - 1][j - 1] + ReplaceCost;
                D[i][j] = std::min({deleteCost, insertCost, replaceCost});
                if (D[i][j] == deleteCost) {
                    changes[i][j] = changes[i - 1][j] + ", Delete " + std::string(1, s1[i - 1]);
                } else if (D[i][j] == insertCost) {
                    changes[i][j] = changes[i][j - 1] + ", Insert " + std::string(1, s2[j - 1]);
                } else {
                    changes[i][j] = changes[i - 1][j - 1] + ", Replace " + std::string(1, s1[i - 1]) + " with " + std::string(1, s2[j - 1]);
                }
            } else {
                D[i][j] = D[i - 1][j - 1];
                changes[i][j] = changes[i - 1][j - 1];
            }
        }
    }
    return {D[M][N], changes[M][N]};
}

int main() {
    std::string s1 = "ПОЛЕНО";
    std::string s2 = "ПЛЕМЯ";

    std::pair<int, std::string> result = levensteinInstruction(s1, s2, 1, 1, 1);

    std::cout << "Number of changes needed: " << result.first << "\n";
    std::cout << "Changes: " << result.second;
}