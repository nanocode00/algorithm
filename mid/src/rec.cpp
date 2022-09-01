#include <iostream>
#include <vector>
using namespace std;

vector<long long int> S;

long long int rec(int n)
{
    S.push_back(1);
    for (int i = 1; i <= n; i++) {
        S.push_back(0);
        for (int j = 0; j < i; j++) {
            S[i] += S[j] * S[i - j - 1];
        }
    }
    return S[n];
}

int main()
{
    for (int i = 1; i <= 30; i++) {
        cout << i << ' ' << rec(i) << '\n';
    }
}