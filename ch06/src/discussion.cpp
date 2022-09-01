#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> disc;

void poss_disc(int T, vector<disc>& D, vector<disc>& P);

int main()
{
    int T;
    cin >> T;
    vector<disc> D(T), P;
    for (int i = 0; i < T; i++) {
        cin >> D[i].first >> D[i].second;
    }

    poss_disc(T, D, P);

    int s = P.size();
    cout << s << '\n';
    for (int i = 0; i < s; i++) {
        cout << P[i].first << ' ' << P[i].second << '\n';
    }
}

void poss_disc(int T, vector<disc>& D, vector<disc>& P)
{
    int e = D[0].second;
    P.clear();
    P.push_back(D[0]);
    for (int i = 1; i < T; i++) {
        if (D[i].first >= e) {
            P.push_back(D[i]);
            e = D[i].second;
        }
    }
}