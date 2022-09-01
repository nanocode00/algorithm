#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> W;
vector<vector<int>> res;
vector<int> vindex;
int n;

void hamiltonian(int i);
bool promising(int i);

int main()
{
    int m, u, v;
    cin >> n >> m;
    W = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        W[u][v] = W[v][u] = true;
    }
    vindex = vector<int>(n);
    vindex[0] = 1;
    hamiltonian(0);
    cout << res.size() << '\n';
}

void hamiltonian(int i)
{
    if (promising(i)) {
        if (i == n - 1) {
            res.push_back(vindex);
        } else {
            for (int j = 2; j <= n; j++) {
                vindex[i + 1] = j;
                hamiltonian(i + 1);
            }
        }
    }
}

bool promising(int i)
{
    if (i == n - 1 && !W[vindex[n - 1]][vindex[0]]) {
        return false;
    } else if (i > 0 && !W[vindex[i - 1]][vindex[i]]) {
        return false;
    } else {
        for (int j = 1; j < i; j++) {
            if (vindex[i] == vindex[j]) {
                return false;
            }
        }
        return true;
    }
}