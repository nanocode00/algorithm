#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> seq_int;
bool is_feasible(seq_int& K, seq_int& deadline);
void schedule(int n, seq_int& deadline, seq_int& J);
void safe_copy(seq_int& dest, seq_int resource);

int main()
{
    int n, max_p = 0;
    seq_int deadline, profit, J;

    cin >> n;
    deadline = seq_int(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> deadline[i];
    }
    profit = seq_int(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    schedule(n, deadline, J);

    for (int i = 1; i < J.size(); i++) {
        max_p += profit[J[i]];
    }
    cout << max_p << '\n' << profit[J[1]];
    for (int i = 2; i < J.size(); i++) {
        cout << ' ' << profit[J[i]];
    }
    cout << '\n';
}

bool is_feasible(seq_int& K, seq_int& deadline)
{
    for (int i = 1; i < K.size(); i++) {
        if (i > deadline[K[i]]) {
            return false;
        }
    }
    return true;
}

void schedule(int n, seq_int& deadline, seq_int& J)
{
    seq_int K;
    J.clear();
    J.push_back(0);
    J.push_back(1);
    for (int i = 2; i <= n; i++) {
        safe_copy(K, J);
        int j;
        for (j = 1; j < K.size() && deadline[K[j]] <= deadline[i]; j++);
        K.insert(K.begin() + j, i);
        if (is_feasible(K, deadline)) {
            safe_copy(J, K);
        }
    }
}

void safe_copy(seq_int& dest, seq_int resource)
{
    dest.resize(resource.size());
    copy(resource.begin(), resource.end(), dest.begin());
}