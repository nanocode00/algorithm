#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define LEN 8

vector<vector<int>> grid(LEN, vector<int>(LEN, 0));
int target_x, target_y;

void divide_triple(int x, int y, int len, int dir)
{
    if (len == 2) {
        if (dir == 0)
            grid[y][x + 1] = dir;
        else
            grid[y][x] = dir;
    } else {
        divide_triple(x + len / 4, y + len / 4, len / 2, dir);
        if (dir != 0)
            divide_triple(x, y, len / 2, 3);
        if (dir != 1)
            divide_triple(x + len / 2, y, len / 2, 2);
        if (dir != 2)
            divide_triple(x, y + len / 2, len / 2, 1);
        if (dir != 3)
            divide_triple(x + len / 2, y + len / 2, len / 2, 0);
    }
}

void divide(int x, int y, int len)
{
    if (len == 1)
        return;
    int x_dir = (target_x < x + len / 2) ? 0 : 1;
    int y_dir = (target_y < y + len / 2) ? 0 : 1;
    divide_triple(x, y, len, x_dir + 2 * y_dir);
    divide(x + x_dir * len / 2, y + y_dir * len / 2, len / 2);
}

void mark()
{
    grid[target_y][target_x] = '*';
    int idx = 'a';
    for (int y = 0; y < LEN; y++) {
        for (int x = 0; x < LEN; x++) {
            int dir = grid[y][x];
            if (dir >= 0 && dir <= 3) {
                if (dir == 0)
                    x--;
                if (dir != 0)
                    grid[y][x] = idx;
                if (dir != 1)
                    grid[y][x + 1] = idx;
                if (dir != 2)
                    grid[y + 1][x] = idx;
                if (dir != 3)
                    grid[y + 1][x + 1] = idx;
                if (dir == 0)
                    x++;
                idx++;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    target_x = rand() % LEN;
    target_y = rand() % LEN;
    divide(0, 0, LEN);
    mark();
    for (int y = 0; y < LEN; y++) {
        for (int x = 0; x < LEN; x++) {
            cout << (char)grid[y][x] << ' ';
        }
        cout << '\n';
    }
}