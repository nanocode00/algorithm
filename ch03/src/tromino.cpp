#include <iostream>
#include <vector>
using namespace std;

int row, col;
int idx = 1;

vector<vector<int>> grid;

void mark(int dir);
void tromino(int x, int y, int n, int tx, int ty);
void print(int n);

int main()
{
    int n;
    cin >> n >> row >> col;
    grid = vector<vector<int>>(n, vector<int>(n, 0));
    tromino(0, 0, n, col, row);
    print(n);
}

void mark(int x, int y, int dir)
{
    if (dir != 0)
        grid[y][x] = idx;
    if (dir != 1)
        grid[y][x + 1] = idx;
    if (dir != 2)
        grid[y + 1][x] = idx;
    if (dir != 3)
        grid[y + 1][x + 1] = idx;
    idx++;
}

void tromino(int x, int y, int n, int tx, int ty)
{
    if (n == 2) {
        if (y == ty) {
            if (x == tx) {
                mark(x, y, 0);
            } else {
                mark(x, y, 1);
            }
        } else {
            if (x == tx) {
                mark(x, y, 2);
            } else {
                mark(x, y, 3);
            }
        }
    } else {
        int m = n / 2;
        if (ty < y + m) {
            if (tx < x + m) {
                mark(x + m - 1, y + m - 1, 0);
                tromino(x, y, m, tx, ty);
                tromino(x + m, y, m, x + m, y + m - 1);
                tromino(x, y + m, m, x + m - 1, y + m);
                tromino(x + m, y + m, m, x + m, y + m);
            } else {
                mark(x + m - 1, y + m - 1, 1);
                tromino(x, y, m, x + m - 1, y + m - 1);
                tromino(x + m, y, m, tx, ty);
                tromino(x, y + m, m, x + m - 1, y + m);
                tromino(x + m, y + m, m, x + m, y + m);
            }
        } else {
            if (tx < x + m) {
                mark(x + m - 1, y + m - 1, 2);
                tromino(x, y, m, x + m - 1, y + m - 1);
                tromino(x + m, y, m, x + m, y + m - 1);
                tromino(x, y + m, m, tx, ty);
                tromino(x + m, y + m, m, x + m, y + m);
            } else {
                mark(x + m - 1, y + m - 1, 3);
                tromino(x, y, m, x + m - 1, y + m - 1);
                tromino(x + m, y, m, x + m, y + m - 1);
                tromino(x, y + m, m, x + m - 1, y + m);
                tromino(x + m, y + m, m, tx, ty);
            }
        }
    }
}

void print(int n)
{
    for (int y = 0; y < n; y++) {
        cout << grid[y][0];
        for (int x = 1; x < n; x++) {
            cout << ' ' << grid[y][x];
        }
        cout << endl;
    }
}