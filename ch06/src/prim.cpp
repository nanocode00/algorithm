#include <iostream>
#include <vector>
#define INF 0xffff
using namespace std;

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void prim(int n, matrix_t& W, set_of_edges& F);
void print(int n, vector<int> v);

int main()
{
    int n, m, u, v;
    matrix_t W;
    set_of_edges F;

    cin >> n >> m;
    W = matrix_t(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        W[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> W[u][v];
        W[v][u] = W[u][v];
    }

    prim(n, W, F);

    for (edge_t e: F) {
        u = e.first;
        v = e.second;
        cout << u << ' ' << v << ' ' << W[u][v] << '\n';
    }
}

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1);

    F.clear();
    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }
    
    print(n, nearest);

    for (int j = 1; j < n; j++) {
        min = INF;
        for (int i = 2; i <= n; i++) {
            if (0 <= distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++) {
            if (distance[i] > W[i][vnear]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
        print(n, nearest);
    }
}

void print(int n, vector<int> v)
{
    cout << v[2];
    for (int i = 3; i <= n; i++) {
        cout << ' ' << v[i];
    }
    cout << '\n';
}