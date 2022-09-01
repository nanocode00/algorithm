#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> W;
vector<vector<int>> res;
vector<int> vcolor;
int n, m;

void m_coloring(int i);
bool promising(int i);

int main()
{
    int k, u, v;
    cin >> n >> k;
    W = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        W[u][v] = W[v][u] = true;
    }
    vcolor = vector<int>(n + 1);
    while (res.size() == 0) {
        m++;
        m_coloring(0);
    }
    cout << m << '\n' << res.size() << '\n';
}

void m_coloring(int i)
{
    if (promising(i)) {
        if (i == n) {
            res.push_back(vcolor);
        } else {
            for (int color = 1; color <= m; color++) {
                vcolor[i + 1] = color;
                m_coloring(i + 1);
            }
        }
    }
}

bool promising(int i)
{
    for (int j = 1; j < i; j++) {
        if (W[i][j] && vcolor[i] == vcolor[j]) {
            return false;
        }
    }
    return true;
}