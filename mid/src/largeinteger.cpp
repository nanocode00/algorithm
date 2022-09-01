#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> LargeInteger;

int threshold = 1;
int cnt = 0;

void print(LargeInteger v);
void roundup_carry (LargeInteger& v);
void remove_leading_zeros(LargeInteger& v);
void ladd(LargeInteger a, LargeInteger b, LargeInteger& c);
void lsub(LargeInteger a, LargeInteger b, LargeInteger& c);
void lmult(LargeInteger a, LargeInteger b, LargeInteger& c);
void pow_by_exp(LargeInteger u, int m, LargeInteger& v);
void div_by_exp(LargeInteger u, int m, LargeInteger& v);
void rem_by_exp(LargeInteger u, int m, LargeInteger& v);
void prod(LargeInteger u, LargeInteger v, LargeInteger& r);

int main()
{
    LargeInteger u, v, r;
    string str;
    cin >> threshold;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        int idx = str.size() - 1 - i;
        if (str.at(idx) >= '0' && str.at(idx) <= '9')
            u.push_back(str.at(idx) - '0');
    }
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        int idx = str.size() - 1 - i;
        if (str.at(idx) >= '0' && str.at(idx) <= '9')
            v.push_back(str.at(idx) - '0');
    }
    prod(u, v, r);
    cout << cnt << '\n';
    print(r);
}

void print(LargeInteger v)
{
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    cout << '\n';
}

void roundup_carry(LargeInteger& v)
{
    int carry = 0;
    for (int i = 0 ; i < v.size(); i++) {
        v[i] += carry;
        if (v[i] >= 0) {
            carry = v[i] / 10;
            v[i] = v[i] % 10;
        } else {
            carry = v[i] / 10 - 1;
            v[i] = v[i] % 10 + 10;
        }
    }
    if (carry != 0)
        v.push_back(carry);
}

void remove_leading_zeros(LargeInteger& v)
{
    while (v.size() != 0 && v.back() == 0)
        v.pop_back();
}

void ladd(LargeInteger a, LargeInteger b, LargeInteger& c)
{
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for(int i = 0; i < c.size(); i++) {
        if (i < a.size()) c[i] += a[i];
        if (i < b.size()) c[i] += b[i];
    }
    roundup_carry(c);
}

void lsub(LargeInteger a, LargeInteger b, LargeInteger& c)
{
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for(int i = 0; i < c.size(); i++) {
        if (i < a.size()) c[i] += a[i];
        if (i < b.size()) c[i] -= b[i];
    }
    roundup_carry(c);
    remove_leading_zeros(c);
}

void lmult(LargeInteger a, LargeInteger b, LargeInteger& c)
{
    c.resize(a.size() + b.size() - 1);
    fill(c.begin(), c.end(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    roundup_carry(c);
}

void pow_by_exp(LargeInteger u, int m, LargeInteger& v)
{
    if (u.size() == 0)
        v.resize(0);
    else {
        v.resize(u.size() + m);
        fill(v.begin(), v.end(), 0);
        copy(u.begin(), u.end(), v.begin() + m);
    }
}

void div_by_exp(LargeInteger u, int m, LargeInteger& v)
{
    if (u.size() < m)
        v.resize(0);
    else {
        v.resize(u.size() - m);
        copy(u.begin() + m, u.end(), v.begin());
    }
}

void rem_by_exp(LargeInteger u, int m, LargeInteger& v)
{
    if (u.size() == 0)
        v.resize(0);
    else {
        int k = (m < u.size()) ? m : u.size();
        v.resize(k);
        copy(u.begin(), u.begin() + k, v.begin());
        remove_leading_zeros(v);
    }
}

void prod(LargeInteger u, LargeInteger v, LargeInteger& r)
{
    cnt++;
    LargeInteger x, y, w, z, p, q, s;
    LargeInteger t1, t2, t3, t4, t5, t6, t7;
    int n = max(u.size(), v.size());
    if (u.size() == 0 || v.size() == 0)
        r.resize(0);
    else if (n <= threshold)
        lmult(u, v, r);
    else {
        int m = n / 2;
        div_by_exp(u, m, x); rem_by_exp(u, m, y);
        div_by_exp(v, m, w); rem_by_exp(v, m, z);
        ladd(x, y, t1);
        ladd(w, z, t2);
        prod(t1, t2, s);
        prod(x, w, p);
        prod(y, z, q);
        pow_by_exp(p, 2 * m, t3);
        lsub(s, p, t4); lsub(t4, q, t5); pow_by_exp(t5, m, t6);
        ladd(t3, t6, t7); ladd(t7, q, r);
    }
}