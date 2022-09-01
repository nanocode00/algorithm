#include <iostream>
#include <vector>
#define INF 0xffff
using namespace std;

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void dijkstra(int n, matrix_t& W, set_of_edges& F);
void path(int v, set_of_edges F, vector<int>& res);
void print(int start, int end, vector<int> v);

int main()
{
    set_of_edges F;
    int n, m, T;
    cin >> n >> m;

    matrix_t W(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> W[u][v];
    }

    cin >> T;
    vector<int> v(T);
    for (int i = 0; i < T; i++) {
        cin >> v[i];
    }

    dijkstra(n, W, F);

    for (edge_t e: F) {
        int u = e.first, v = e.second;
        cout << u << ' ' << v << ' ' << W[u][v] << '\n';
    }

    vector<int> res;
    for (int i = 0; i < T; i++) {
        path(v[i], F, res);
        print(0, res.size() - 1, res);
        res.clear();
    }
}

void dijkstra(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> touch(n + 1), length(n + 1);

    F.clear();
    for (int i = 2; i <= n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    print(2, n, touch);
    
    for (int j = 1; j < n; j++) {
        min = INF;
        for (int i = 2; i <= n; i++) {
            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(touch[vnear], vnear));
        for (int i = 2; i <= n; i++) {
            if (length[i] > length[vnear] + W[vnear][i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
        print(2, n, touch);
    }
}

void path(int v, set_of_edges F, vector<int>& res)
{
    for (edge_t e: F) {
        if (e.second == v) {
            if (e.first == 1)
                res.push_back(1);
            else {
                path(e.first, F, res);
            }
            res.push_back(v);
            return;
        }
    }
}

void print(int start, int end, vector<int> v)
{
    cout << v[start];
    for (int i = start + 1; i <= end; i++) {
        cout << ' ' << v[i];
    }
    cout << '\n';
}