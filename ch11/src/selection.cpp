#include <iostream>
#include <vector>

using namespace std;

int selection(int low, int high, int k);
void partition(int low, int high, int& pivotpoint);
void print_list(vector<int> S);

vector<int> S;

int selection(int low, int high, int k)
{
    int pivotpoint;

    if (low == high) {
        return S[low];
    } else {
        partition(low, high, pivotpoint);
        print_list(S);
        if (k == pivotpoint) {
            return S[pivotpoint];
        } else if (k < pivotpoint) {
            return selection(low, pivotpoint - 1, k);
        } else {
            return selection(pivotpoint + 1, high, k);
        }
    }
}

void partition(int low, int high, int& pivotpoint)
{
    int i, j, pivotitem;

    pivotitem = S[low];
    j = low;
    for (i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
        }
    }
    pivotpoint = j;
    swap(S[low], S[high]);
}

void print_list(vector<int> S)
{
    cout << S[0];
    for (int i = 1; i < S.size(); i++) {
        cout << ' ' << S[i];
    }
    cout << '\n';
}