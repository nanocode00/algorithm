#include <iostream>
#include <vector>
using namespace std;

vector<int> S;
int n;

int min()
{
    int smallest = 10000;
    for (int i = 0; i < n; i++) {
        if (smallest > S[i])
            smallest = S[i];
    }
    return smallest;
}

int max()
{
    int largest = 1;
    for (int i = 0; i < n; i++) {
        if (largest < S[i])
            largest = S[i];
    }
    return largest;
}

int main()
{
    cin >> n;
    S = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
    cout << min() << '\n' << max();
}