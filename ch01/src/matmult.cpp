#include <iostream>
#include <vector>
using namespace std;

int n, k, m;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> C = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int t = 0; t < k; t++) {
                C[i][j] += A[i][t] * B[t][j];
            }
        }
    }
    return C;
}

int main()
{
    cin >> n >> k >> m;
    vector<vector<int>> A = vector<vector<int>>(n, vector<int>(k, 0));
    vector<vector<int>> B = vector<vector<int>>(k, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }
    vector<vector<int>> C = multiply(A, B);
    cout << C[0][0];
    for (int j = 1; j < m; j++) {
        cout << ' ' << C[0][j];
    }
    for (int i = 1; i < n; i++) {
        cout << '\n' << C[i][0];
        for (int j = 1; j < m; j++)
            cout << ' ' << C[i][j];
    }
}