#include <iostream>
#include <vector>

using namespace std;

void find_both(int n, vector<int> S, int& small, int& large);

void find_both(int n, vector<int> S, int& small, int& large)
{
    small = S[1];
    large = S[1];
    for (int i = 2; i <= n; i++) {
        if (S[i] < small) {
            small = S[i];
        } else if (S[i] > large) {
            large = S[i];
        }
    }
}