#include <iostream>
#include <vector>
#define INF 999
using namespace std;

typedef vector<vector<int>> matrix_t;

void floyd2(int n, matrix_t& W, matrix_t& D, matrix_t& P);
void path(matrix_t& P, int u, int v, vector<int>& p);

int main()
{
    int n, m;
    int u, v, w;
    int T;
    matrix_t W, D, P;
    matrix_t t;
    vector<int> p;

    cin >> n >> m;
    W = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    D = vector<vector<int>>(n + 1, vector<int>(n + 1));
    P = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    cin >> T;
    t = vector<vector<int>>(T, vector<int>(2));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> t[i][j];
        }
    }

    floyd2(n, W, D, P);

    for (int i = 1; i <= n; i++) {
        cout << D[i][1];
        for (int j = 2; j <= n; j++) {
            cout << ' ' << D[i][j];
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        cout << P[i][1];
        for (int j = 2; j <= n; j++) {
            cout << ' ' << P[i][j];
        }
        cout << '\n';
    }

    for (int i = 0; i < T; i++) {
        if (D[t[i][0]][t[i][1]] == INF)
            cout << "NONE\n";
        else {
            if (p.size() > 0)
                p.clear();
            path(P, t[i][0], t[i][1], p);
            cout << t[i][0];
            for (int i = 0; i < p.size(); i++)
                cout << ' ' << p[i];
            cout << ' ' << t[i][1] <<'\n';
        }
    }
}

void floyd2(int n, matrix_t& W, matrix_t& D, matrix_t& P)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
}

void path(matrix_t& P, int u, int v, vector<int>& p)
{
    int k = P[u][v];
    if (k != 0) {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}