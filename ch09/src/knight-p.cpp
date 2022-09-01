#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> W;
vector<int> vindex, row, col;
int v, cnt, cnt_l;

void make_graph(int n, int m, vector<vector<bool>>& W);
void hamiltonian(int i);
bool promising(int i);
void show_middle(int a);

    int n, m, T;
int main()
{

    cin >> n >> m >> T;
    row = vector<int>(T);
    col = vector<int>(T);
    for (int i = 0; i < T; i++) {
        cin >> row[i] >> col[i];
    }

    v = n * m;
    make_graph(n, m, W);
    vindex = vector<int>(v);

    vindex[0] = 1;
    hamiltonian(0);
    cout << cnt_l << '\n';

    for (int i = 0; i < T; i++) {
        vindex[0] = col[i] * n + row[i] + 1;
        cnt = 0;
        hamiltonian(0);
        cout << cnt << '\n';
    }
}

void make_graph(int n, int m, vector<vector<bool>>& W)
{
    int x[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
    int y[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
    W = vector<vector<bool>>(v + 1, vector<bool>(v + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 8; k++) {
                if (i + x[k] >= 0 && i + x[k] < m && j + y[k] >= 0 && j + y[k] < n) {
                    W[i * n + j + 1][(i + x[k]) * n + j + y[k] + 1] = true;
                }
            }
        }
    }
}

void hamiltonian(int i)
{
    if (promising(i)) {
        if (i == v - 1) {
            cnt++;
            if (W[vindex[v - 1]][vindex[0]]) {
                cnt_l++;
            }
        } else {
            bool flag = false;
            for (int j = 1; j <= v; j++) {
                vindex[i + 1] = j;
                if (promising(i + 1)) {
                    flag = true;
                }
                hamiltonian(i + 1);
            }
            if (!flag) {
                show_middle(i);
            }
        }
    }
}

bool promising(int i)
{
    if (i > 0 && !W[vindex[i - 1]][vindex[i]]) {
        return false;
    } else {
        for (int j = 0; j < i; j++) {
            if (vindex[i] == vindex[j]) {
                return false;
            }
        }
        return true;
    }
}

void show_middle(int a)
{
    vector<int> grid = vector<int>(v + 1);
    for (int i = 0; i <= a; i++) {
        grid[vindex[i]] = i + 1;
    }
    cout << '\n';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i * n + j + 1] << ' ';
        }
        cout << '\n';
    }
}