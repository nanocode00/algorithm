#include <iostream>

using namespace std;

bool isprime(int p);

int main()
{
    int n, p, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (isprime(p)) cnt++;
    }
    cout << cnt << '\n';
}

bool isprime(int p)
{
    for (int i = 2; i * i <= p; i++)
        if (p % i == 0) return false;
    return p > 1;
}