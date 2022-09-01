#include <iostream>
#include <vector>
#define INF 999999
using namespace std;

typedef vector<vector<int>> matrix_t;

void minmult(int n, vector<int>& d, matrix_t& M, matrix_t& P);
int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M);
void order(int i, int j, matrix_t& P, string& s);
void print(int n, matrix_t& m);

int main()
{
    int n;
    string s;
    cin >> n;
    vector<int> d = vector<int>(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> d[i];
    }
    matrix_t M = vector<vector<int>>(n + 1, vector<int>(n + 1));
    matrix_t P = vector<vector<int>>(n + 1, vector<int>(n + 1));
    minmult(n, d, M, P);
    order(1, n, P, s);
    print(n, M);
    print(n, P);
    cout << M[1][n] << '\n' << s << '\n';
}

void minmult(int n, vector<int>& d, matrix_t& M, matrix_t& P)
{
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal, k;
            M[i][j] = minimum(i, j, k, d, M);
            P[i][j] = k;
        }
}

int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M)
{
    int minValue = INF, value;
    for (int k = i; k <= j - 1; k++) {
        value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void order(int i, int j, matrix_t& P, string& s)
{
    s += "(";
    if (i == j)
        s += "A" + to_string(i);
    else {
        int k = P[i][j];
        order(i, k, P, s);
        order(k + 1, j, P, s);
    }
    s += ")";
}

void print(int n, matrix_t& m)
{
    for (int i = 1; i <= n; i++) {
        cout << m[i][i];
        for (int j = i + 1; j <= n; j++)
            cout << ' ' << m[i][j];
        cout << '\n';
    }
}