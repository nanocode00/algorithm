#include <iostream>
#include <vector>
using namespace std;

long long int fibonacci(long long int n)
{
    vector<long long int> F;
    if (n <= 1)
        return n;
    else {
        F.push_back(0);
        F.push_back(1);
        for (int i = 2; i <= n; i++) {
            F.push_back(F[i - 2] + F[i - 1]);
        }
        return F[n];
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2) {
        cout << fibonacci(atoll(argv[1])) << endl;
    } else if (argc == 1) {
        long long int n;
        cin >> n;
        cout << fibonacci(n) << endl;
    }
}