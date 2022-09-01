#include <iostream>
#define MAX 5000000

using namespace std;

void eratosthenes(int n);
int factorization(int k);

bool prime[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0;

    eratosthenes(MAX);

    for (int i = 1000; i <= 10000; i++) {
        if (factorization(i) == 2) {
            cnt++;
            cout << i << '\n';
        }
    }
    cout << cnt << '\n';
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

int factorization(int k)
{
    int res = 0;
    for (int i = 2; i * i <= k; i++)
        if (prime[i])
            if (k % i == 0) {
                res++;
                for (; k % i == 0; k /= i);
            }
    if (k > 1)
        res++;
    return res;
}