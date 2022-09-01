#include <iostream>
#include <vector>

using namespace std;

void find_both2(int n, vector<int> S, int& small, int& large);

void find_both2(int n, vector<int> S, int& small, int& large)
{
    if (S[1] < S[2]) {
        small = S[1];
        large = S[2];
    } else {
        small = S[2];
        large = S[1];
    }
    for (int i = 3; i <= n - 1; i += 2) {
        if (S[i] < S[i + 1]) {
            if (S[i] < small) {
                small = S[i];
            }
            if (S[i + 1] > large) {
                large = S[i + 1];
            }
        } else {
            if (S[i + 1] < small) {
                small = S[i + 1];
            }
            if (S[i] > large) {
                large = S[i];
            }
        }
    }
}