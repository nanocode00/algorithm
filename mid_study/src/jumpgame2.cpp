#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid, dir;

void jumpgame(int tx, int ty);

int main()
{
    int C, n;
    vector<string> ans;
    cin >> C;
    ans = vector<string>(C);
    for (int k = 0; k < C; k++) {
        cin >> n;
        grid = vector<vector<int>>(n, vector<int>(n));
        dir = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        jumpgame(n - 1, n - 1);
        if (dir[0][0] == 0) {
            ans[k] = "NO";
        } else {
            ans[k] = "YES";
        }
        grid.clear();
        dir.clear();
    }
    for (int k = 0; k < C; k++) {
        cout << ans[k] << '\n';
    }
}

void jumpgame(int tx, int ty)
{
    for (int i = 1; i <= ty; i++) {
        if (grid[ty - i][tx] == i) {
            if (dir[ty - i][tx] == 0) {
                dir[ty - i][tx] = 1;
                jumpgame(tx, ty - i);
            }
        }
    }

    for (int i = 1; i <= tx; i++) {
        if (grid[ty][tx - i] == i) {
            if (dir[ty][tx - i] == 0) {
                dir[ty][tx - i] = 2;
                jumpgame(tx - i, ty);
            }
        }
    }
}