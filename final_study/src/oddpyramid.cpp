#include <iostream>
#include <vector>

using namespace std;

long long pow(int x, int y);

int main()
{
    int t;
    vector<int> n;

    cin >> t;
    n = vector<int>(t);
    for (int i = 0; i < t; i++)
        cin >> n[i];
    
    for (int i = 0; i < t; i++) {
        cout << '#' << i + 1 << ' ' << 2 * pow(n[i], 2) - 4 * (long long)n[i] + 3 << ' ' << 2 * pow(n[i], 2) - 1 << '\n';
    }
}

long long pow(int x, int y)
{
    long long res = 1;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}