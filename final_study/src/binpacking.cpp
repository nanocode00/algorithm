#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b);

int main()
{
    vector<int> ls;
    int n, l, q = 0;

    cin >> n >> l;
    ls = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> ls[i];
    
    sort(ls.begin(), ls.end(), compare);

    for (int i = 1; q + i <= n; q++)
        if (ls[q] + ls[n - i] <= l)
            i++;

    cout << q << '\n';
}

bool compare(int a, int b)
{
    return a > b;
}