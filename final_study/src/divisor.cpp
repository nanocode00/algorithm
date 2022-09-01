#include <iostream>
#include <vector>

using namespace std;

int find_num(int n, vector<int> rd);

int main()
{
    int n;
    vector<int> rd;

    cin >> n;
    rd = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> rd[i];
    }

    cout << find_num(n, rd) << '\n';
}

int find_num(int n, vector<int> rd)
{
    vector<int> prime, degree;
    int p, div, cnt, idx, ip;

    for (int i = 0; i < n; i++) {
        p = 2;
        div = rd[i];

        while (true) {
            if (div % p == 0) {
                cnt = 0;

                for (idx = 0; idx < prime.size(); idx++)
                    if (p == prime[idx]) break;
                if (idx == prime.size()) {
                    prime.push_back(p);
                    degree.push_back(0);
                }

                while (div % p == 0) {
                    div /= p;
                    cnt += 1;
                }

                if (degree[idx] < cnt)
                    degree[idx] = cnt;
            }

            if (div == 1) break;

            while (true) {
                p++;
                for (ip = 2; ip * ip <= p; ip++)
                    if (p % ip == 0) break;
                if (ip * ip >= p) break;
            }
        }
    }

    int res = 1;
    for (int i = 0; i < prime.size(); i++)
        for (int j = 0; j < degree[i]; j++)
            res *= prime[i];
    if (prime.size() == 1) {
        res *= prime[0];
    }
    return res;
}