#include <iostream>
#include <vector>
using namespace std;

vector<int> S;
int n, cnt;

void printList()
{
    cout << S[1];
    for (int i = 2; i <= n; i++) {
        cout << ' ' << S[i];
    }
}

void partition(int low, int high, int& pivotpoint)
{
    swap(S[low], S[high]);
    int pivotitem = S[low];

    int j = low;
    for (int i = low + 1; i <= high; i++)
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++;
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++;
}

void quicksort(int low, int high)
{
    int pivotpoint;
    if (low < high) {
        partition(low, high, pivotpoint);
        if (low == 1 && high == n) {
            printList();
        }
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}

int main()
{
    cin >> n;
    S = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    quicksort(1, n);
    cout << '\n' << cnt << '\n';
    printList();
}