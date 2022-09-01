#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct item* item_ptr;
typedef struct item {
    int id;
    int weight;
    int profit;
    int profit_per_unit;
} item_t;

int n, W;
vector<item_t> items;
vector<int> w, p;

bool compare_item(item_t i, item_t j) {
    return i.profit_per_unit > j.profit_per_unit;
}

int knapsack(vector<vector<int>>& P)
{
    for (int i = 0; i <= n; i++) {
        P[i][0] = 0;
    }
    for (int j = 1; j <= W; j++) {
        P[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            P[i][j] = (w[i] > j) ? P[i - 1][j] : max(P[i - 1][j], p[i] + P[i - 1][j - w[i]]);
        }
    }

    return P[0][W];
}