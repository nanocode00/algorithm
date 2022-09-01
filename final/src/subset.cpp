#include <iostream>
#include <vector>
using namespace std;

vector<int> w, res_list;
vector<bool> include;
vector<vector<bool>> res;
int W;

void sum_of_subsets(int i, int weight, int total);
bool promising(int i, int weight, int total);
void print_res(int n);

int main()
{
    int n, total = 0;
    cin >> n >> W;
    w = vector<int>(n + 1);
    include = vector<bool>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        total += w[i];
    }
    sum_of_subsets(0, 0, total);
    print_res(n);
}

void sum_of_subsets(int i, int weight, int total)
{
    cout << i << ' ' << weight << ' ' << total << '\n';
    if (promising(i, weight, total)) {
        if (weight == W) {
            res.push_back(include);
        } else {
            include[i + 1] = true;
            sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
            include[i + 1] = false;
            sum_of_subsets(i + 1, weight, total - w[i + 1]);
        }
    }
}

bool promising(int i, int weight, int total)
{
    return weight + total >= W && (weight == W || weight + w[i + 1] <= W);
}

void print_res(int n)
{
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (res[i][j]) {
                res_list.push_back(w[j]);
            }
        }
        cout << res_list[0];
        for (int j = 1; j < res_list.size(); j++) {
            cout << ' ' << res_list[j];
        }
        cout << '\n';
        res_list.clear();
    }
}