#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long __int64;

vector<int> result;
vector<int> col;
vector<int> check_row;
int n = 0;
__int64 MAX = 0;
int cnt = 0;

__int64 VectorToInt(vector<int> v)
{
   __int64 decimal = 1;
   __int64 total = 0;
   for (auto& it : v)
   {
      decimal = 1;
      while (decimal <= it)
         decimal *= 10;
      total *= decimal;
      total += it;
   }
   return total;
}

void print_solution()
{
   cnt++;
   result.clear();
   for (int j = 1; j <= n; j++) {
      result.push_back(col[j]);
   }
   __int64 a = VectorToInt(result);
   MAX = (a > MAX) ? a : MAX;
}

bool promising(int i)
{
   int k = 1, flag = true;
   while (k < i && flag) {
      if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
         flag = false;
      k++;
   }
   return flag;
}

void queens(int i)
{
   if (promising(i)) {
      if (i == n) { //마지막 행까지 채워졌을 때
         print_solution();
      }
      else //계속 반복
         for (int j = 1; j <= n; j++) {
            col[i + 1] = j;
            queens(i + 1);
         }
   }
}

int main()
{
   cin >> n;
   col.resize(n + 1, 0);
   result.resize(n + 1, 0);
   queens(0);
   cout << cnt << endl;
   cout << MAX;
}