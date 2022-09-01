#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y)
{
    y = x + y;
    x = y - x;
    y = y - x;
}

int main()
{
    int x = 2, y = 3;
    swap(x, y);
    cout << x << ' ' << y << '\n';
}