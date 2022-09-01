#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<int> S;

void merge2(int low, int mid, int high)
{
    cnt++;
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);

    while (i <= mid && j <= high)
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    if (i > mid)
        while (j <= high)
            U[k++] = S[j++];
    else
        while (i <= mid)
            U[k++] = S[i++];
    for (int t = low; t <=high; t++)
        S[t] = U[t - low];
}

void mergesort2(int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid);
        mergesort2(mid + 1, high);
        merge2(low, mid, high);
    }
}

int main()
{
    cin >> n;
    S = vector<int>(n);
    for (int i = 0; i < n; i++)
    cin >> S[i];
    mergesort2(0, n - 1);
    cout << cnt << '\n' << S[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << S[i];
}