#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF 999999

typedef vector<vector<int>> matrix_t;

bool isIn(int i, int A);
int diff(int A, int j);
int count(int A);
int minimum(int n, int i, int& minJ, int A, matrix_t& W, matrix_t& D);
void travel(int n, matrix_t& W, matrix_t& D, matrix_t& P, int& minlength);
void tour(int v, int A, matrix_t& P);


int main()
{
   int n, m, u, v, w, minlength;
   cin >> n >> m;
   matrix_t W(n + 1, vector<int>(n + 1, INF));

   for (int i = 1; i <= n; i++)
      W[i][i] = 0; //대각선은 0으로 모두 초기화 

   for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      W[u][v] = w;
   }

   matrix_t D(n + 1, vector<int>(pow(2, n - 1), 0));
   matrix_t P(n + 1, vector<int>(pow(2, n - 1), 0));

   travel(n, W, D, P, minlength);

   cout << endl << minlength << endl;
   cout << "1" << ' ';
   tour(1, pow(2, n - 1) - 1, P);
   cout << endl;

   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < pow(2, n - 1); j++)
         if (D[i][j] >= INF || D[i][j] == 0)
            continue;
         else
            cout << i << " " << j << " " << D[i][j] << " " << endl;
   }
}

void travel(int n, matrix_t& W, matrix_t& D, matrix_t& P, int& minlength) { //
   int i, j, k, A;

   int subset_size = pow(2, n - 1);
   for (i = 2; i <= n; i++)
      D[i][0] = W[i][1];
   for (k = 1; k <= n - 2; k++)
      for (A = 0; A < subset_size; A++) {
         if (count(A) != k) continue;
         for (i = 2; i <= n; i++) {
            if (isIn(i, A)) continue;
            D[i][A] = minimum(n, i, j, A, W, D);
            P[i][A] = j;
         }
      }
   A = subset_size - 1; // A = V - {v1}
   D[1][A] = minimum(n, 1, j, A, W, D);
   P[1][A] = j;
   minlength = D[1][A];
}

int count(int A) { //
   int cnt = 0;
   for (; A != 0; A >>= 1)
      if (A & 1) cnt++;
   return cnt;
}

bool isIn(int i, int A) { //
   return (A & (1 << (i - 2))) != 0;
}

int minimum(int n, int i, int& minJ, int A, matrix_t& W, matrix_t& D) {//
   int minV = INF, value;
   for (int j = 2; j <= n; j++) {
      if (!isIn(j, A)) continue;
      value = W[i][j] + D[j][diff(A, j)];
      if (minV > value) {
         minV = value;
         minJ = j;
      }
   }
   return minV;
}

int diff(int A, int j) { //
   return (A & ~(1 << (j - 2)));
}

void tour(int v, int A, matrix_t& P) {//
   int k = P[v][A];
   if (A == 0)
      cout << "1";
   else {
      cout << k << " ";
      tour(k, diff(A, k), P);
   }
}