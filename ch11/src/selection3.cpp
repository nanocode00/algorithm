#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int selection3(vector<int> S, int low, int high, int k);
void partition3(vector<int> S, int low, int high, int& pivotpoint);

int selection3(vector<int> S, int low, int high, int k)
{
    int pivotpoint;
    if (low == high) {
        return S[low];
    } else {
        partition3(S, low, high, pivotpoint);
        if (k == pivotpoint) {
            return S[pivotpoint];
        } else if (k < pivotpoint) {
            return selection3(S, low, pivotpoint - 1, k);
        } else {
            return selection3(S, pivotpoint + 1, high, k);
        }
    }
}

void partition3(vector<int> S, int low, int high, int& pivotpoint)
{
    int i, j, randspot, pivotitem;

    randspot = low + rand() % (high - low + 1);
    pivotitem = S[randspot];

    swap(S[low], S[randspot]);
    j = low;
    for (i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}