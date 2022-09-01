#include <iostream>
#include <vector>
using namespace std;

vector<int> S;
int n;
int cnt;

int searchindex(int low, int high)
{
    int mid;

    if (low > high)
        return -1;
    else {
        cnt++;
        mid = (low + high) / 2;
        if (mid == S[mid])
            return mid;
        else if (mid < S[mid])
            return searchindex(low, mid - 1);
        else
            return searchindex(mid + 1, high);
    }
}

int main()
{
    cin >> n;
    S = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
    cout << searchindex(0, n - 1) << '\n' << cnt;
}