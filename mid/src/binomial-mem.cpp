#include <iostream>
#include <vector>
#define MAX 256
using namespace std;

vector<vector<int>> B;

int binom(int n, int k)
{
    if (B[n][k] == 0) {
        if (k == 1 || k == n) {
            B[n][k] = 2;
        } else {
            if (B[n - 1][k - 1] == 0)
                binom(n - 1, k - 1);
            if (B[n - 1][k] == 0)
                binom(n - 1, k);
            B[n][k] = (B[n - 1][k - 1] + B[n - 1][k]) % 1000;
        }

    }
    return B[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    B = vector<vector<int>>(n + 1, vector<int>(n + 1));
    cout << binom(n, k) << '\n'; 
}