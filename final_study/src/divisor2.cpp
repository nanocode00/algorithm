#include <iostream>
#include <vector>

using namespace std;

void find_both(int n, vector<int> S, int& small, int& large);

int main()
{
    int n, small, large;
    vector<int> rd;

    cin >> n;
    rd = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> rd[i];
    }

    find_both(n, rd, small, large);

    cout << small * large << '\n';
}

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