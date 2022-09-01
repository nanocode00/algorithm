#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct edge {
    int u, v, w;
} edge_t;
struct edge_compare {
    bool operator()(edge_t e1, edge_t e2) {
        return e1.w > e2.w;
    }
};
typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> PriorityQueue;

void dset_init(int n);
int dset_find(int i);
void dset_merge(int p, int q);
void kruskal(int n, int m, set_of_edges& E, set_of_edges& F);

vector<int> dset;

int main()
{
    int n, m;
    set_of_edges E, F;
    cin >> n >> m;
    E = set_of_edges(m);
    for (int i = 0; i < m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    kruskal(n, m, E, F);
    for (edge e: F) {
        cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    }
}

void dset_init(int n)
{
    dset.resize(n + 1);
    for (int i = 1; i <= n; i++)
        dset[i] = i;
}

int dset_find(int i)
{
    while (dset[i] != i)
        i = dset[i];
    return i;
}

void dset_merge(int p, int q)
{
    dset[p] = q;
}

void kruskal(int n, int m, set_of_edges& E, set_of_edges& F)
{
    int p, q;
    edge_t e;
    PriorityQueue PQ;

    for (edge_t e: E)
        PQ.push(e);
    F.clear();
    dset_init(n);
    
    while (F.size() < n - 1) {
        e = PQ.top(); PQ.pop();
        p = dset_find(e.u);
        q = dset_find(e.v);
        if (p != q) {
            dset_merge(p, q);
            F.push_back(e);
        }
    }
}