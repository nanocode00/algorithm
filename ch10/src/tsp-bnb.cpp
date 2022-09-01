#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#define INF 999

using namespace std;

typedef vector<int> ordered_set;

typedef struct node *node_pointer;
typedef struct node {
    int level;
    ordered_set path;
    int bound;
} nodetype;

struct compare {
    bool operator()(node_pointer u, node_pointer v)
    {
        return u->bound > v->bound;
    }
};
typedef priority_queue<node_pointer, vector<node_pointer>, compare> priority_queue_of_node;

void travel2(ordered_set& opttour, int& minlength);
node_pointer create_node(int level, ordered_set path);
int length(ordered_set path);
int bound(node_pointer v);
bool hasOutgoing(int v, ordered_set path);
bool hasIncoming(int v, ordered_set path);
bool isIn(int v, ordered_set path);
int remaining_vertex(ordered_set path);
void print_node(node_pointer v);

vector<vector<int>> W;
int n;

int main()
{
    int m, u, v, minlength;
    ordered_set opttour;
    cin >> n >> m;
    W = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> W[u][v];
    }
    for (int i = 1; i <= n; i++) {
        W[i][i] = 0;
    }
    travel2(opttour, minlength);
    cout << minlength << '\n' << opttour[0];
    for (int i = 1; i < opttour.size(); i++) {
        cout << ' ' << opttour[i];
    }
    cout << '\n';
}

void travel2(ordered_set& opttour, int& minlength)
{
    priority_queue_of_node PQ;
    node_pointer u, v;

    minlength = INF;
    u = create_node(0, ordered_set(1, 1));
    print_node(u);
    PQ.push(u);
    while (!PQ.empty()) {
        v = PQ.top();
        PQ.pop();

        if (v->bound < minlength) {
            for (int i = 2; i <= n; i++) {
                if (isIn(i, v->path)) {
                    continue;
                }
                u = create_node(v->level + 1, v->path);
                u->path.push_back(i);
                if (u->level == n - 2) {
                    u->path.push_back(remaining_vertex(u->path));
                    u->path.push_back(1);
                    u->bound = bound(u);
                    print_node(u);
                    if (length(u->path) < minlength) {
                        minlength = length(u->path);
                        opttour = u->path;
                    }
                } else {
                    u->bound = bound(u);
                    print_node(u);
                    if (u->bound < minlength) {
                        PQ.push(u);
                    }
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

int length(ordered_set path)
{
    int len = 0;
    for (auto it = path.begin(); it != path.end() - 1; it++) {
        len += W[*it][*(it + 1)];
    }
    return len;
}

int bound(node_pointer v)
{
    int lower = length(v->path);
    for (int i = 1; i <= n; i++) {
        if (hasOutgoing(i, v->path)) {
            continue;
        }
        int min = INF;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (j == 1 && i == v->path[v->path.size() - 1]) {
                continue;
            }
            if (hasIncoming(j, v->path)) {
                continue;
            }
            if (min > W[i][j]) {
                min = W[i][j];
            }
        }
        lower += min;
    }
    return lower;
}

bool hasOutgoing(int v, ordered_set path)
{
    for (auto it = path.begin(); it != path.end() - 1; it++) {
        if (*it == v) {
            return true;
        }
    }
    return false;
}

bool hasIncoming(int v, ordered_set path)
{
    for (auto it = path.begin() + 1; it != path.end(); it++) {
        if (*it == v) {
            return true;
        }
    }
    return false;
}

bool isIn(int v, ordered_set path)
{
    for (auto it = path.begin(); it != path.end(); it++) {
        if (*it == v) {
            return true;
        }
    }
    return false;
}

int remaining_vertex(ordered_set path)
{
    int j = 2;
    for (; j <= n; j++) {
        if (!isIn(j, path)) {
            break;
        }
    }
    return j;
}

void print_node(node_pointer v)
{
    
    cout << v->level << ' ';
    if (v->bound >= INF) {
        cout << "INF";
    } else {
        cout << v->bound;
    }
    for (int i = 0; i < v->path.size(); i++) {
        cout << ' ' << v->path[i];
    }
    cout << '\n';
}