#include <iostream>
#include <vector>
#include <cmath>
#define INF 999

using namespace std;

typedef vector<vector<int>> matrix_t;

void travel(int n, matrix_t& W, matrix_t& D, matrix_t& P, int& minlength);
int count(int A);
bool isIn(int i, int A);
int minimum(int n, int i, int& minJ, int A, matrix_t& W, matrix_t& D);
int diff(int A, int j);
void tour(int v, int A, matrix_t& P);

int main()
{
    matrix_t W, D, P;
    int n, m, u, v, minlength;
    cin >> n >> m;
    W = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    D = vector<vector<int>>(n + 1, vector<int>(pow(2, n - 1)));
    P = vector<vector<int>>(n + 1, vector<int>(pow(2, n - 1)));
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> W[u][v];
    }
    for (int i = 1; i <= n; i++) {
        W[i][i] = 0;
    }
    travel(n, W, D, P, minlength);
    cout << minlength << "\n1 ";
    tour(1, pow(2, n - 1)- 1, P);
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < pow(2, n - 1); j++) {
            if (D[i][j] != 0 && D[i][j] != INF) {
                cout << i << ' ' << j << ' ' << D[i][j] << '\n';
            }
        }
    }
}

void travel(int n, matrix_t& W, matrix_t& D, matrix_t& P, int& minlength)
{
    int i, j, k, A;
    int subset_size = pow(2, n - 1);
    for (i = 2; i <= n; i++) {
        D[i][0] = W[i][1];
    }
    for (k = 1; k <= n - 2; k++) {
        for (int A = 0; A < subset_size; A++) {
            if (count(A) != k) {
                continue;
            }
            for (i = 2; i <= n; i++) {
                if (isIn(i, A)) {
                    continue;
                }
                D[i][A] = minimum(n, i, j, A, W, D);
                P[i][A] = j;
            }
        }
    }
    A = subset_size - 1;
    D[1][A] = minimum(n, 1, j, A, W, D);
    P[1][A] = j;
    minlength = D[1][A];
}

int count(int A)
{
    int cnt = 0;
    for(; A != 0; A >>= 1) {
        if (A & 1) {
            cnt++;
        }
    }
    return cnt;
}

bool isIn(int i, int A)
{
    return (A & (1 << (i - 2))) != 0;
}

int minimum(int n, int i, int& minJ, int A, matrix_t& W, matrix_t& D)
{
    int minV = INF, value;
    for (int j = 2; j <= n; j++) {
        if (!isIn(j, A)) {
            continue;
        }
        int value = W[i][j] + D[j][diff(A, j)];
        if (minV > value) {
            minV = value;
            minJ = j;
        }
    }
    return minV;
}

int diff(int A, int j)
{
    return (A & ~(1 << (j - 2)));
}

void tour(int v, int A, matrix_t& P)
{
    int k = P[v][A];
    if (A == 0) {
        cout << 1;
    } else {
        cout << k << ' ';
        tour(k, diff(A, k), P);
    }
}