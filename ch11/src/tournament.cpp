#include <iostream>
#include <vector>

using namespace std;

typedef struct item {
    int index;
    int value;
} item_type;
typedef vector<item_type> item_list;

void tournament(int n, item_list S, vector<item_list> L, item_type& largest);
void find_largest(int n, item_list L, item_type& second_largest);

int main()
{
    int n;
    item_type largest, second_largest;
    item_list S(n);
    vector<item_list> L(S.size());

    tournament(n, S, L, largest);
    find_largest(n, L[largest.index], second_largest);
    cout << second_largest.value << endl;
}

void tournament(int n, item_list S, vector<item_list> L, item_type& largest)
{
    if (n == 1)
        largest = S[0];
    else {
        item_list winner;
        for (int i = 0; i < n - 1; i+= 2) {
            if (S[i].value > S[i + 1].value) {
                winner.push_back(S[i]);
                L[i].push_back(S[i + 1]);
            } else {
                winner.push_back(S[i]);
                L[i + 1].push_back(S[i]);
            }
        }
        return tournament(n / 2, winner, L, largest);
    }
}

void find_largest(int n, item_list L, item_type& second_largest)
{

}