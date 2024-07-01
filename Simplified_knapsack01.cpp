#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else 
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
int main() {
    std::vector<int> weights = {10, 20, 30};  // Weights of the items
    std::vector<int> values = {60, 100, 120}; // Values of the items
    int capacity = 50;  // Capacity of the knapsack
    int n = weights.size();  // Number of items
    
    int maxValue = knapsack(capacity, weights, values, n);
    
    std::cout << "0/1 Knapsack Total Value: " << maxValue << std::endl;    
    return 0;
} //https://onecompiler.com/cpp/42htyf2yd
