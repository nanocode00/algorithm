#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> p, w;

typedef struct node* node_pointer;
typedef struct node { //각 노드 정보 
   int level;
   int weight;
   int profit;
   float bound;
}nodetype;

struct compare {
   bool operator()(node_pointer u, node_pointer v) {
      if (u->bound < v->bound)
         return true;
      return false;
   }
};
typedef priority_queue<node_pointer, vector<node_pointer>, compare> priority_queue_of_node;

int W = 0; //배낭 무게 
int n = 0;
int maxprofit = 0;

float bound(node_pointer u) {
   int j, k;
   int totweight;
   float result;

   if (u->weight >= W)
      return 0;
   else {
      result = u->profit;
      j = u->level + 1;
      totweight = u->weight;
      while (j <= n && totweight + w[j] <= W) {
         totweight = totweight + w[j];
         result = result + p[j];
         j++;
      }
      k = j;
      if (k <= n)
         result = result + (W - totweight) * p[k] / w[k];
      return result;
   }
}




node_pointer create_node(int level, int weight, int profit) {
   node_pointer v = (node_pointer)malloc(sizeof(nodetype));
   v->level = level;
   v->weight = weight;
   v->profit = profit;
   v->bound = bound(v);
   return v;
}


void knapsack() {
   priority_queue_of_node PQ;
   node_pointer u, v;
   int cnt = 0;
   maxprofit = 0;
   PQ.push(create_node(0, 0, 0));
   while (!PQ.empty()) {

      v = PQ.top(); PQ.pop(); //PQ에서 가장 우선순위 높은 것 삭제 후 반환
      if (v->bound > maxprofit) {
         u = create_node(v->level + 1, v->weight + w[v->level + 1], v->profit + p[v->level + 1]);
         if (cnt == 0) {
            cout << "0 0 0 " << bound(u) << endl; cnt++;
         }
         if (u->weight <= W && u->profit > maxprofit) {
            maxprofit = u->profit;
         }
         u->bound = bound(u);
         cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
         if (u->bound > maxprofit) {
            PQ.push(u);
         }
         u->bound = bound(u);
         u = create_node(v->level + 1, v->weight, v->profit);
         if (u->bound > maxprofit) {
            PQ.push(u);
         }
         cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;

      }
   }
}

int main()
{
   cin >> n >> W;
   p.resize(n + 1);
   w.resize(n + 1);

   for (int i = 1; i <= n; i++)
   {
      cin >> w[i];
   }
   for (int i = 1; i <= n; i++)
   {
      cin >> p[i];
   }
   knapsack();
   cout << maxprofit << endl;
}