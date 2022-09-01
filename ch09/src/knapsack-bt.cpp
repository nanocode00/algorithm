#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct item* item_ptr;
typedef struct item {
    int id;
    int weight;
    int profit;
    float profit_per_unit;
} item_t;

bool compare(item_t a, item_t b)
{
    return a.profit_per_unit > b.profit_per_unit;
}

int n, W, maxprofit;
vector<item> items;
vector<bool> include, bestset;

void knapsack(int i, int profit, int weight);
bool promising(int i, int profit, int weight);
int calc_bound(int i, int profit, int weight);

int main()
{
    cin >> n >> W;
    items = vector<item>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i].weight;
    }
    for (int i = 1; i <= n; i++) {
        cin >> items[i].profit;
    }
    for (int i = 1; i <= n; i++) {
        items[i].id = i;
        items[i].profit_per_unit = (float)items[i].profit / items[i].weight;
    }

    sort(items.begin() + 1, items.end(), compare);

    include = vector<bool>(n + 1);
    knapsack(0, 0, 0);
    cout << maxprofit << '\n';
    for (int i = 1; i < bestset.size(); i++) {
        if (bestset[i]) {
            cout << items[i].weight << ' ' << items[i].profit << '\n';
        }
    }
}

void knapsack(int i, int profit, int weight)
{
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        bestset.resize(include.size());
        copy(include.begin(), include.end(), bestset.begin());
    }
    
    cout << i << ' ' << weight << ' ' << profit << ' ' << calc_bound(i, profit, weight) << ' ' << maxprofit << '\n';

    if (promising(i, profit, weight)) {
        include[i + 1] = true;
        knapsack(i + 1, profit + items[i + 1].profit, weight + items[i + 1].weight);
        include[i + 1] = false;
        knapsack(i + 1, profit, weight);
    }
}

bool promising(int i, int profit, int weight)
{
    return weight < W && calc_bound(i, profit, weight) > maxprofit;
}

int calc_bound(int i, int profit, int weight)
{
    int j = i + 1, totweight = weight, bound = profit;
    for (; j <= n && totweight + items[j].weight <= W; j++) {
        totweight += items[j].weight;
        bound += items[j].profit;
    }
    if (totweight + items[j].weight > W) {
        if (totweight > W) {
            bound += (W - totweight) * items[j - 1].profit_per_unit;
        } else {
            bound += (W - totweight) * items[j].profit_per_unit;
        }
        //bound += (W - totweight) * items[j - (int)(totweight > W)].profit_per_unit;
    }
    return bound;
}