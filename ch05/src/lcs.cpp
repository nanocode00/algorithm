#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;

void lcs(string& x, string& y, matrix_t& C, matrix_t& B);
void get_lcs(int i, int j, string& x, matrix_t B, string& res);

int main()
{
    string x, y, res;
    cin >> x >> y;
    int m = x.size(), n = y.size();
    matrix_t C = matrix_t(m + 1, vector<int>(n + 1));
    matrix_t B = matrix_t(m + 1, vector<int>(n + 1));
    lcs(x, y, C, B);
    cout << C[m][n] << '\n';
    get_lcs(m, n, x, B, res);
    cout << res << '\n';
}

void lcs(string& x, string& y, matrix_t& C, matrix_t& B)
{
    int m = x.size();
    int n = y.size();
    x = ' ' + x;
    y = ' ' + y;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 1;
            } else {
                if (C[i][j - 1] > C[i - 1][j]) {
                    C[i][j] = C[i][j - 1];
                    B[i][j] = 2;
                } else {
                    C[i][j] = C[i - 1][j];
                    B[i][j] = 3;
                }
            }
        }
    }
}

void get_lcs(int i, int j, string& x, matrix_t B, string& res)
{
    if (i != 0 && j != 0) {
        if (B[i][j] == 1) {
            get_lcs(i - 1, j - 1, x, B, res);
            res += x[i];
        } else if (B[i][j] == 2) {
            get_lcs(i, j - 1, x, B, res);
        } else if (B[i][j] == 3) {
            get_lcs(i - 1, j, x, B, res);
        }
    }
}