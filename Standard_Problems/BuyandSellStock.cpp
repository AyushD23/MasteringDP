#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Calculates max profit from one buy and one sell
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int minPrice = prices[0];
    int maxP = 0;

    for (int i = 1; i < prices.size(); ++i) {
        maxP = max(maxP, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return maxP;
}

int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices1) << endl; 
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit: " << maxProfit(prices2) << endl; 
    return 0;
}
