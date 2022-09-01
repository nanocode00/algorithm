#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int select(int n, vector<int> S, int k);
int selection2(vector<int> S, int low, int high, int k);
void partition2(vector<int> S, int low, int high, int& pivotpoint);
int median(vector<int> S, int first, int last);

int select(int n, vector<int> S, int k)
{
    return selection2(S, 1, n, k);
}

int selection2(vector<int> S, int low, int high, int k)
{
    int pivotpoint;
    if (low == high) {
        return S[low];
    } else {
        partition2(S, low, high, pivotpoint);
        if (k == pivotpoint) {
            return S[pivotpoint];
        } else if (k < pivotpoint) {
            return selection2(S, low, pivotpoint - 1, k);
        } else {
            return selection2(S, pivotpoint + 1, high, k);
        }
    }
}

void partition2(vector<int> S, int low, int high, int& pivotpoint)
{
    int arraysize = high - low + 1;
    int r = (int)ceil((double)arraysize / 5);
    int i, j, mark, first, last, pivotitem;
    vector<int> T(r + 1);
    for (i = 1; i <= r; i++) {
        first = low + 5 * i - 5;
        last = min(low + 5 * i - 1, low + arraysize - 1);
        T[i] = median(S, first, last);
    }
    pivotitem = select(r, T, (r + 1) / 2);
    j = low;
    for (i = low; i <= high; i++) {
        if (S[i] == pivotitem) {
            swap(S[i], S[j]);
            mark = j++;
        } else if (S[i] < pivotitem) {
            swap(S[i], S[j++]);
        }
    }
    pivotpoint = j - 1;
    swap(S[mark], S[pivotpoint]);
}

int median(vector<int> S, int first, int last)
{

}