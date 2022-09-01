#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid, dir;

void jumpgame(int tx, int ty);
void makepath(int tx, int ty, string& res);

int main()
{
    int n;
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n));
    dir = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    jumpgame(n - 1, n - 1);
    string res;
    makepath(n - 1, n - 1, res);
    cout << res << '\n';
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

void makepath(int tx, int ty, string& res)
{
    if (dir[0][0] == 0) {
        res = "impossible";
    } else {
        int x = 0, y = 0;
        res = "(0, 0)";
        while (x != tx || y != ty) {
            if (dir[y][x] == 1) {
                y += grid[y][x];
            } else if (dir[y][x] == 2) {
                x += grid[y][x];
            } else
                break;
            res += " -> (" + to_string(x) + ", " + to_string(y) + ")";
        }
    }
}