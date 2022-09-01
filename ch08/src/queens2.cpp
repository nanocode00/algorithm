#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> col;
int n;

void queens(int i);
bool promising(int i);
void print_res(int n);

int main()
{
    cin >> n;
    col = vector<int>(n + 1);
    queens(0);
    print_res(n);
}

void queens(int i)
{
    if (promising(i)) {
        if (i == n) {
            res.push_back(col);
        } else {
            for (int j = 1; j <= n; j++) {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}

bool promising(int i)
{
    for (int k = 1; k < i; k++) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k) {
            return false;
        }
    }
    return true;
}

void print_res(int n)
{
    int s = res.size();
    string max = "", val;
    for (int i = 0; i < s; i++) {
        val = "";
        for (int j = 1; j <= n; j++) {
            val += to_string(res[i][j]);
        }
        if (val > max) {
            max = val;
        }
    }
    cout << s << '\n' << max << '\n';
}