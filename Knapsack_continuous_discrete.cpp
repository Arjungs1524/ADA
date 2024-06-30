#include <iostream>
#include <vector>
#include <algorithm>
struct Item {
    int weight;
    int value;
    Item(int w, int v) : weight(w), value(v) {}
};

double knapsack(std::vector<Item>& items, int capacity, bool isContinuous) {

    std::sort(items.begin(), items.end(), [](Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    });
    
    double totalValue = 0.0;
    for (const auto& item : items) {
        if (capacity - item.weight >= 0) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            if (isContinuous) {
                totalValue += item.value * ((double)capacity / item.weight);
            }
            break;
        }
    }
    return totalValue;
}
int main() {
    std::vector<Item> items = { {10, 60}, {20, 100}, {30, 120} };
    int capacity = 50;
    
    std::cout << "Discrete Knapsack Total Value: " << knapsack(items, capacity, false) << std::endl;
    capacity = 50;
    std::cout << "Continuous Knapsack Total Value: " << knapsack(items, capacity, true) << std::endl;
    return 0;
} // https://onecompiler.com/cpp/42hsac4pb,  https://www.youtube.com/watch?v=m1p-eWxrt6g
