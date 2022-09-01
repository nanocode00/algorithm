#include <iostream>
#include <vector>
using namespace std;

vector<int> row, col, vx, vy;
int n, m, v, T, cnt, cnt_l;
int x[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int y[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void tour(int i);
bool promising(int i);

int main()
{
    cin >> n >> m >> T;

    row = vector<int>(T);
    col = vector<int>(T);
    for (int i = 0; i < T; i++) {
        cin >> row[i] >> col[i];
    }

    v = m * n;
    vx = vector<int>(v);
    vy = vector<int>(v);

    vx[0] = 0;
    vy[0] = 0;
    cnt_l = 0;
    tour(0);
    cout << cnt_l << '\n';

    for (int i = 0; i < T; i++) {
        vx[0] = col[i];
        vy[0] = row[i];
        cnt = 0;
        tour(0);
        cout << cnt << '\n';
    }
}

void tour(int i)
{
    if (promising(i)) {
        if (i == v - 1) {
            cnt++;
            for (int j = 0; j < 8; j++) {
                if (vx[0] == vx[v - 1] + x[j] && vy[0] == vy[v - 1] + y[j]) {
                    cnt_l++;
                    break;
                }
            }
        } else {
            for (int j = 0; j < 8; j++) {
                if (vx[i] + x[j] >= 0 && vx[i] + x[j] < m
                    && vy[i] + y[j] >= 0 && vy[i] + y[j] < n) {
                    vx[i + 1] = vx[i] + x[j];
                    vy[i + 1] = vy[i] + y[j];
                    tour(i + 1);
                }
            }
        }
    }
}

bool promising(int i)
{
    for (int j = 0; j < i; j++) {
        if (vx[i] == vx[j] && vy[i] == vy[j]) {
            return false;
        }
    }
    return true;
}