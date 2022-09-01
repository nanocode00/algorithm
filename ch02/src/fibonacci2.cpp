#include <iostream>
using namespace std;

int MAX;

int fibonacci(int n) {
    int a = 0, b = 1, c;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MAX;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n >> MAX;
    cout << fibonacci(n) << '\n';
}