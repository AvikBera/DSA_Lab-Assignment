#include <iostream>
#include <vector>
using namespace std;

// Solved using Counting Sort, as required by the problem statement.
int maxIceCream(vector<int>& costs, int coins) {
    int maxCost = 0;
    for (int c : costs) maxCost = max(maxCost, c);

    // Counting sort: count occurrences of each cost value
    vector<int> count(maxCost + 1, 0);
    for (int c : costs) count[c]++;

    // Greedily buy the cheapest bars first (walk the counting array
    // in increasing order of price)
    int bars = 0;
    for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
        int canBuy = min(count[cost], coins / cost);
        bars += canBuy;
        coins -= canBuy * cost;
    }
    return bars;
}

int main() {
    vector<int> costs1 = {1, 3, 2, 4, 1};
    cout << "coins=7  -> Max bars: " << maxIceCream(costs1, 7) << endl;

    vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    cout << "coins=5  -> Max bars: " << maxIceCream(costs2, 5) << endl;

    vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    cout << "coins=20 -> Max bars: " << maxIceCream(costs3, 20) << endl;

    return 0;
}
