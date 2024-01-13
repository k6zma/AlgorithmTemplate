#include <string>
#include <vector>

#include <iostream>

int levensteinInstruction(std::string s1, std::string s2, int InsertCost, int DeleteCost, int ReplaceCost) {
    int M = s1.size();
    int N = s2.size();
    std::vector<std::vector<int>> D(M + 1, std::vector<int>(N + 1));

    D[0][0] = 0;
    for (int j = 1; j <= N; ++j) {
        D[0][j] = D[0][j - 1] + InsertCost;
    }
    for (int i = 1; i <= M; ++i) {
        D[i][0] = D[i - 1][0] + DeleteCost;
        for (int j = 1; j <= N; ++j) {
            if (s1[i - 1] != s2[j - 1]) {
                D[i][j] = std::min({D[i - 1][j] + DeleteCost, D[i][j - 1] + InsertCost, D[i - 1][j - 1] + ReplaceCost});
            } else {
                D[i][j] = D[i - 1][j - 1];
            }
        }
    }
    return D[M][N];
}

int main() {
    std::string s1 = "ПОЛЕНО";
    std::string s2 = "ПЛЕМЯ";

    int changes = levensteinInstruction(s1, s2, 1, 1, 1);
    std::cout << "Number of changes needed: " << changes;
}