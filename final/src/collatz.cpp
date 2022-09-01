#include <iostream>
#define INF 99999999
#define MAX 999999
using namespace std;

int collatz(int n);

int main()
{
    int c = 0;
    for (int i = 1; i <= 1000; i++) {
        if (collatz(i) == INF) {
            c++;
        }
    }
    cout << c << '\n';
}

int collatz(int n) {
    int cnt = 1;
    int l[MAX] = {n};
    cout << n << ' ';
    for (; l[cnt - 1] != 1; cnt++) {
        if (l[cnt - 1] % 2 == 0)
            l[cnt] = l[cnt - 1] / 2;
        else
            l[cnt] = l[cnt - 1] * 3 - 1;
        cout << l[cnt] << ' ';
        for (int i = 0; i < cnt; i++)
            if (l[cnt] == l[i]) {
                cout << '\n';
                return INF;
            }
    }
    cout << '\n';
    return cnt;
}