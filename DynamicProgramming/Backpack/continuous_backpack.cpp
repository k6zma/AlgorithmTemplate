#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double costPerWeight;
    int index;

    Item(int weight, int value, int index) : weight(weight), value(value), index(index) {
        costPerWeight = (double)value / weight;
    }
};

bool compareItems(const Item &a, const Item &b) {
    return a.costPerWeight > b.costPerWeight;
}

int main() {
    int N, W;
    std::cin >> W >> N;

    std::vector<Item> items;
    for (int i = 0; i < N; ++i) {
        int weight, value;
        std::cin >> weight >> value;
        items.emplace_back(weight, value, i + 1);
    }

    std::sort(items.begin(), items.end(), compareItems);

    double total_cost = 0.0;
    double total_weight = 0.0;
    std::vector<std::pair<int, double>> ans;

    for (int i = 0; i < N; ++i) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            total_cost += items[i].value;
            total_weight += items[i].weight;
            ans.emplace_back(items[i].index, 1.0);
        } else {
            double fraction = (double)W / items[i].weight;
            total_cost += W * items[i].costPerWeight;
            total_weight += W;
            ans.emplace_back(items[i].index, fraction);
            break;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        std::cout << "Item " << ans[i].first << ": " << ans[i].second * 100 << "%\n";
    }

    std::cout << "Total weight: " << total_weight << "\n";
    std::cout << "Total cost: " << total_cost;
}
