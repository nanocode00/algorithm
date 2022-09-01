#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

int main()
{
    int m, n, i, j;
    cin >> m >> n;
    for (int i = 2; i <= n; i++) {
        for (j = 0; j < p.size() && p[j] * p[j] <= i; j++)
            if (i % p[j] == 0) break;
        if (j >= p.size() || p[j] * p[j] > i) {
            p.push_back(i);
            if (i >= m) cout << i << '\n';
        }
    }
}