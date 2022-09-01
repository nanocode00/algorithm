#include <iostream>
#include <cstdlib>

using namespace std;

bool isprime(int t);

int* p;

int main()
{
    int n, i, j = 0, maxk = 2;
    int* k;

    cin >> n;
    k = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        cin >> k[i];
        if (k[i] > maxk)
            maxk = k[i];
    }

    p = (int*)malloc(sizeof(int) * 348513);
    p[j++] = 2;
    for (i = 3; i <= maxk; i += 2)
        if (isprime(i))
            p[j++] = i;

    for (i = 0; i < n; i++) {
        for (j = 0; k[i] != 1 && j < 348513; j++) {
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