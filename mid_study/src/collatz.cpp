#include <iostream>
#define INF 999999
using namespace std;

int collatz(int n);

int main()
{
    int max = 0, maxi, c;
    for (int i = 90000; i <= 99999; i++) {
        c = collatz(i);
        if (max < c) {
            max = c;
            maxi = i;
        }
    }
    cout << maxi << ' ' << max << '\n';
}

int collatz(int n) {
    int cnt = 1, a = n;
    while (a != 1) {
        if (a % 2 == 0)
            a /= 2;
        else
            a = a * 3 + 1;
        cnt++;
    }
    return cnt;
}