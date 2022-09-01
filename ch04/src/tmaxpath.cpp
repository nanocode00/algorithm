#include <iostream>
#include <vector>
using namespace std;

int tmaxsum(int n, vector<vector<int>>& T, vector<vector<int>>& P);
void tmaxpath(int n, vector<vector<int>>& T, vector<vector<int>>& P, vector<int>& res);

int main()
{
    int n;
    int tmax;
    vector<vector<int>> T, P;
    vector<int> res;

    cin >> n;
    T = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        T[i] = vector<int>(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> T[i][j];
        }
    }

    tmax = tmaxsum(n, T, P);
    tmaxpath(n, T, P, res);

    cout << tmax << '\n' << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << ' ' << res[i];
    }
    cout << '\n';
}

int tmaxsum(int n, vector<vector<int>>& T, vector<vector<int>>& P)
{
    vector<vector<int>> S = vector<vector<int>>(n);
    P = vector<vector<int>>(n - 1);
    S[n - 1] = vector<int>(n);
    for (int i = 0; i < n; i++)
        S[n - 1][i] = T[n - 1][i];
    for (int i = n - 2; i >= 0; i--) {
        S[i] = vector<int>(i + 1);
        P[i] = vector<int>(i + 1);
        for (int j = 0; j <= i; j++) {
            if (S[i + 1][j] > S[i + 1][j + 1]) {
                S[i][j] = T[i][j] + S[i + 1][j];
                P[i][j] = j;
            } else {
                S[i][j] = T[i][j] + S[i + 1][j + 1];
                P[i][j] = j + 1;
            }
        }
    }
    return S[0][0];
}

void tmaxpath(int n, vector<vector<int>>& T, vector<vector<int>>& P, vector<int>& res)
{
    res.clear();
    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        res.push_back(T[i][p]);
        p = P[i][p];
    }
    res.push_back(T[n - 1][p]);
}