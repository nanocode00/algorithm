#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0xFFFF

typedef vector<int> ordered_set;

typedef struct node* node_pointer;
struct node {
   int level;
   int bound;
   ordered_set path;
} node_t;

struct node_compare {
   bool operator()(node_pointer u, node_pointer v) {
      if (u->bound > v->bound)
         return true;
      return false;
   }
};

typedef priority_queue<node_pointer, vector<node_pointer>, node_compare> priority_queue_of_node;

void travel2(ordered_set& opttour, int& minlength);
node_pointer create_node(int level, ordered_set path);
int length(ordered_set path);
int bound(node_pointer u);
bool hasOutgoing(int v, ordered_set path);
bool hasIncoming(int v, ordered_set path);
bool isIn(int v, ordered_set path);
int remaining(ordered_set path);
void print(node_pointer u);

int n;
vector<vector<int>> W;

int main()
{
   int m, u, v, w, minlength;
   cin >> n >> m;
   W.resize(n + 1, vector<int>(n + 1, INF));
   for (int i = 1; i <= n; i++)
      W[i][i] = 0;
   while (m-- > 0) {
      cin >> u >> v >> w;
      W[u][v] = w;
   }
   vector<int> opttour;
   travel2(opttour, minlength);
   cout << minlength << endl;
   for (int i = 0; i < opttour.size(); i++)
      if (i != opttour.size() - 1)
         cout << opttour[i] << " ";
      else
         cout << opttour[i] << endl;
}

void travel2(ordered_set& opttour, int& minlength)
{
   priority_queue_of_node PQ;
   minlength = INF;
   node_pointer u, v;

   v = create_node(0, vector<int>(1, 1));
   print(v);

   PQ.push(v);
   while (!PQ.empty()) {
      v = PQ.top(); PQ.pop();

      if (v->bound < minlength) {
         for (int i = 2; i <= n; i++) {
            if (isIn(i, v->path)) continue;

            u = create_node(v->level + 1, v->path);
            u->path.push_back(i);

            if (u->level == n - 2) {
               u->path.push_back(remaining(u->path));
               u->path.push_back(1);
               u->bound = bound(u);
               print(u);
               if (length(u->path) < minlength) {
                  minlength = length(u->path);
                  // opttour = u.path; deepcopy u.path to opttour
                  opttour.resize(u->path.size());
                  copy(u->path.begin(), u->path.end(), opttour.begin());
               }
            }
            else {
               u->bound = bound(u);
               print(u);
               if (u->bound < minlength)
                  PQ.push(u);
            }
         }
      }
   }
}

node_pointer create_node(int level, ordered_set path)
{
    node_pointer v = (node_pointer)malloc(sizeof(node));
    v->level = level;
    v->path = vector<int>(path.size());
    copy(path.begin(), path.end(), v->path.begin());
    v->bound = bound(v);
    
    return v;
}

int length(ordered_set path) {
   vector<int>::iterator it;
   int len = 0;
   for (it = path.begin(); it != path.end(); it++)
      if (it != path.end() - 1)
         len += W[*it][*(it + 1)];
   return len;
}

/*
 * returns the bound for a node using the considerations
 * in the textbook (Refer to Section 6.2).
 */
int bound(node_pointer u)
{
   // start from the length of current path
   int lowerbound = length(u->path);
   for (int i = 1; i <= n; i++) {
      // Do not consider vertices already visited.
      if (hasOutgoing(i, u->path)) continue;
      int min = INF;
      for (int j = 1; j <= n; j++) {
         // Do not include self-loops.
         if (i == j) continue;
         // Do not include an edge to which i cannot returns.
         if (j == 1 && i == u->path[u->path.size() - 1]) continue;
         // Do not include edges already in the path.
         if (hasIncoming(j, u->path)) continue;
         if (min > W[i][j]) min = W[i][j];
      }
      lowerbound += min;
   }
   return lowerbound;
}

bool hasOutgoing(int v, ordered_set path) {
   vector<int>::iterator it;
   for (it = path.begin(); it != path.end() - 1; it++)
      if (*it == v) return true;
   return false;
}

bool hasIncoming(int v, ordered_set path) {
   vector<int>::iterator it;
   for (it = path.begin() + 1; it != path.end(); it++)
      if (*it == v) return true;
   return false;
}

bool isIn(int v, ordered_set path)
{
   for (int i = 0; i < path.size(); i++)
      if (v == path[i]) return true;
   return false;
}

/*
 * returns the missing node in the given path.
 */
int remaining(ordered_set path) {
   int s = 0;
   for (int i : path)
      s += i;
   return n * (n + 1) / 2 - s;
}

void print(node_pointer u)
{
    
    cout << u->level << " ";
    if (u->bound >= INF) cout << "INF";
    else cout << u->bound;
    for (int i = 0; i < u->path.size(); i++)
        cout << " " << u->path[i];
    cout << "\n";
}