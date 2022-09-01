#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct node* node_pointer;
typedef struct node {
    int level;
    int weight;
    int profit;
} nodetype;

typedef queue<node_pointer> queue_of_node;

void knapsack5();
float bound(node_pointer u);
node_pointer create_node(int level, int weight, int profit);

vector<int> w, p;
int n, W, maxprofit;

void knapsack5()
{
    queue_of_node Q;
    node_pointer u, v;
    maxprofit = 0;

    Q.push(create_node(0, 0, 0));
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        u = create_node(v->level + 1,
            v->weight + w[v->level + 1],
            v->profit + p[v->level + 1]);
        if (u->weight <= W && u->profit > maxprofit) {
            maxprofit = u->profit;
        }
        if (bound(u) > maxprofit) {
            Q.push(u);
        }
        u = create_node(v->level + 1, v->weight, v->profit);
        if (bound(u) > maxprofit) {
            Q.push(u);
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
        for (; j <= n && totweight + w[j] <= W; j++) {
            totweight += w[j];
            result += p[j];
        }

        if (j <= n) {
            result += (W - totweight) * ((float)p[j] / w[j]);
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
    return v;
}