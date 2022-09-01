#include <iostream>
#include <vector>
using namespace std;

int MAX = 10;

int binomial(int n, int k);

int main()
{
    int n, k;
    cin >> n >> k >> MAX;
    cout << binomial(n, k) << '\n';
}

int binomial(int n, int k)
{
    if (n < 2 * k)
        k = n - k;
    vector<int> b = vector<int>(k + 1);
    b[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            b[j] = (b[j] + b[j - 1]) % MAX;
        }
    }
    return b[k];
}