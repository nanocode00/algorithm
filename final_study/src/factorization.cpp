#include <iostream>
#include <vector>

using namespace std;

bool isprime(int t);

vector<int> p;

int main()
{
    int n, i, j = 0;
    vector<int> k;

    cin >> n;
    k = vector<int>(n);
    for (i = 0; i < n; i++)
        cin >> k[i];

    p = vector<int>(348513);
    p[j++] = 2;
    for (i = 3; i <= 5000000; i++)
        if (isprime(i))
            p[j++] = i;

    for (i = 0; i < n; i++) {
        for (j = 0; k[i] != 1 && j < p.size(); j++) {
            while (k[i] % p[j] == 0) {
                k[i] /= p[j];
                cout << p[j] << ' ';
            }
        }
        cout << '\n';
    }
}

bool isprime(int t)
{
    for (int i = 0; p[i] * p[i] <= t; i++)
        if (t % p[i] == 0) return false;
    return true;
}