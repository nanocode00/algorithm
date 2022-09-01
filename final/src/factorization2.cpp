#include <iostream>
#define MAX 12700800

using namespace std;

int minF[MAX + 1];

void calc_minF();
void factorization(int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    calc_minF();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        factorization(k);
    }
}

void calc_minF()
{
    for (int i = 2; i <= MAX; i++)
        minF[i] = i;
    
    for (int i = 2; i * i <= MAX; i++)
        if (minF[i] == i)
            for (int j = i * i; j <= MAX; j += i)
                if (minF[j] == j)
                    minF[j] = i;
}

void factorization(int k)
{
    for (; k > 1; k /= minF[k])
        cout << minF[k] << ' ';
    cout << '\n';
}
