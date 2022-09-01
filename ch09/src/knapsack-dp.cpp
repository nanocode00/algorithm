#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct item* item_ptr;
typedef struct item {
    int id;
    int weight;
    int profit;
    int profit_per_unit;
} item_t;

bool compare(item_t a, item_t b)
{
    return a.profit_per_unit > b.profit_per_unit;
}

int n;
vector<item_t> items;
vector<int> W;

int knapsack(int n, int W, vector<item_t> items, map<pair<int, int>, int>& P);

int main()
{
    int T;
    map<pair<int, int>, int> P;
    cin >> n;
    items = vector<item>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i].weight;
    }
    for (int i = 1; i <= n; i++) {
        cin >> items[i].profit;
    }
    for (int i = 1; i <= n; i++) {
        items[i].id = i;
        items[i].profit_per_unit = items[i].profit / items[i].weight;
    }

    cin >> T;
    W = vector<int>(T);
    for (int i = 0; i < T; i++) {
        cin >> W[i];
    }

    sort(items.begin() + 1, items.end(), compare);

    for (int i = 0; i < T; i++) {
        cout << knapsack(n, W[i], items, P) << '\n';
        for (auto it: P) {
            cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
        }
        P.clear();
    }
}

int knapsack(int n, int W, vector<item_t> items, map<pair<int, int>, int>& P)
{
    if (n == 0 || W <= 0) {
        return 0;
    }

    int lvalue = (P.find(make_pair(n - 1, W)) != P.end()) ?
        P[make_pair(n - 1, W)] : knapsack(n - 1, W, items, P);
    
    int rvalue = (P.find(make_pair(n - 1, W - items[n].weight)) != P.end()) ?
        P[make_pair(n - 1, W - items[n].weight)] : knapsack(n - 1, W - items[n].weight, items, P);

    P[make_pair(n, W)] = (items[n].weight > W) ? lvalue : max(lvalue, items[n].profit + rvalue);
    return P[make_pair(n, W)];
}