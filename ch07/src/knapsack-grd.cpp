#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct item* item_ptr;
typedef struct item {
    int id;
    int weight;
    int profit;
    int profit_per_unit;
} item_t;

struct compare {
    bool operator()(item_t i, item_t j)
    {
        return i.profit_per_unit < j.profit_per_unit;
    }
};

typedef priority_queue<item, vector<item>, compare> PrirorityQueue;

int n;
vector<item_t> items, taken;

void knapsack(int& maxprofit, int& totweight, int W, PrirorityQueue& PQ);

int main()
{
    int T, maxprofit, totweight;
    vector<int> W;
    PrirorityQueue PQ;
    
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

    for (int i = 0; i < T; i++) {
        for (int j = 1; j <= n; j++) {
            PQ.push(items[j]);
        }
        knapsack(maxprofit, totweight, W[i], PQ);
        cout << maxprofit << '\n';
        for (int j = 0; j < taken.size(); j++) {
            cout << taken[j].weight << ' ' << taken[j].profit << '\n';
        }
        taken.clear();
        while (!PQ.empty()) {
            PQ.pop();
        }
    }
}

void knapsack(int& maxprofit, int& totweight, int W, PrirorityQueue& PQ)
{
    maxprofit = totweight = 0;
    while (!(PQ.empty() || W == totweight)) {
        item i = PQ.top();
        PQ.pop();
        if (totweight + i.weight > W) {
            i.profit = (W - totweight) * i.profit_per_unit;
            i.weight = (W - totweight);
        }
        maxprofit += i.profit;
        totweight += i.weight;
        taken.push_back(i);
    }
}