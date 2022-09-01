#include <iostream>
#include <vector>
#define SIZE 5

using namespace std;

typedef vector<int> isq;

void print(vector<int> v);

int main()
{
    vector<int> a, b;
    isq u, v;
    a = vector<int>(SIZE);
    for (int i = 0; i < a.size(); i++) {
        a[i] = i + 1;
    }
    print(a);
    b = a;
    print(b);
    a[0] = 5;
    print(a);
    print(b);

    cout << '\n';

    u = isq(SIZE);
    for (int i = 0; i < u.size(); i++) {
        u[i] = u.size() - i;
    }
    print(u);
    v = u;
    print(v);
    u[0] = 1;
    print(u);
    print(v);
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}