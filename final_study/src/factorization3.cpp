#include <iostream>
#define MAX 5000000

using namespace std;

void eratosthenes(int n);
void factorization(int k);

bool prime[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    eratosthenes(MAX);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        factorization(k);
    }
}

void eratosthenes(int n)
{
    for (int i = 2; i <= n; i++)
        prime[i] = true;

    for (int i = 2; i * i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
}

void factorization(int k)
{
    for (int i = 2; i * i <= k; i++)
        if (prime[i])
            for (; k % i == 0; k /= i)
                cout << i << ' ';
    if (k > 1)
        cout << k;
    cout << '\n';
}