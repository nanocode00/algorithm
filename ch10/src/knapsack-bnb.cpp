#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct node* node_pointer;
typedef struct node {
    int level;
    int weight;
    int profit;
    float bound;
} nodetype;

struct compare {
    bool operator()(node_pointer u, node_pointer v)
    {
        return u->bound < v->bound;
    }
};
typedef priority_queue<node_pointer, vector<node_pointer>, compare> priority_queue_of_node;

void knapsack6();
float bound(node_pointer u);
node_pointer create_node(int level, int weight, int profit);
bool comp(int a, int b);

vector<int> w, p, o;
int n, W, maxprofit;

int main()
{
    cin >> n >> W;

    w = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    p = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    o = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        o[i] = i;
    }

    sort(o.begin() + 1, o.end(), comp);

    knapsack6();
    cout << maxprofit << '\n';
}

void knapsack6()
{
    priority_queue_of_node PQ;
    node_pointer u, v;
    maxprofit = 0;
    PQ.push(create_node(0, 0, 0));
    while (!PQ.empty()) {
        v = PQ.top();
        PQ.pop();
        if (v->bound > maxprofit) {
            u = create_node(v->level + 1, v->weight + w[o[v->level + 1]], v->profit + p[o[v->level + 1]]);
            if (u->weight <= W && u->profit > maxprofit) {
                maxprofit = u->profit;
            }
            if (u->bound > maxprofit) {
                PQ.push(u);
            }
            u = create_node(v->level + 1, v->weight, v->profit);
            if (u->bound > maxprofit) {
                PQ.push(u);
            }
        }
    }
}

float bound(node_pointer u)
{
    if (u->weight >= W) {
        return 0;
    } else {
        int j = u->level + 1, totweight = u->weight;
        float result = u->profit;
        for (; j <= n && totweight + w[o[j]] <= W; j++) {
            totweight += w[o[j]];
            result += p[o[j]];
        }

        if (j <= n) {
            result += (W - totweight) * ((float)p[o[j]] / w[o[j]]);
        }
        return result;
    }
}

node_pointer create_node(int level, int weight, int profit)
{
    node_pointer v = (node_pointer)malloc(sizeof(node));
    v->level = level;
    v->weight = weight;
    v->profit = profit;
    v->bound = bound(v);
    cout << v->level << ' ' << v->weight << ' ' << v->profit << ' ' << v->bound << '\n';
    return v;
}

bool comp(int a, int b)
{
    return (float)p[a] / w[a] > (float)p[b] / w[b];
}