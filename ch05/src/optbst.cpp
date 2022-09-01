#include <iostream>
#include <vector>
#include <cstdlib>
#define INF 999999
using namespace std;

typedef vector<vector<int>> matrix_t;
typedef struct node *node_ptr;
typedef struct node {
    int key;
    node_ptr left;
    node_ptr right;
} node_t;

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R);
int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A);
void print(int n, matrix_t& m);
node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R);
node_ptr create_node(int key);
void preorder(node_ptr t, vector<int>& res);
void inorder(node_ptr t, vector<int>& res);
void printres(vector<int>& res);

int main()
{
    int n;
    cin >> n;
    vector<int> keys = vector<int>(n + 1);
    vector<int> p = vector<int>(n + 1);
    vector<int> res;
    for (int i = 1; i <= n; i++)
        cin >> keys[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    matrix_t A = matrix_t(n + 2, vector<int>(n + 2));
    matrix_t R = matrix_t(n + 2, vector<int>(n + 2));
    optsearchtree(n, p, A, R);
    print(n, A);
    print(n, R);
    cout << A[1][n] << '\n';
    node_ptr t = tree(1, n, keys, R);
    preorder(t, res);
    printres(res);
    res.clear();
    inorder(t, res);
    printres(res);
}

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R)
{
    for (int i = 1; i <= n; i++) {
        A[i][i - 1] = 0; A[i][i] = p[i];
        R[i][i - 1] = 0; R[i][i] = i;
    }
    A[n + 1][n] = R[n + 1][n] = 0;

    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal, k;
            A[i][j] = minimum(i, j, k, p, A);
            R[i][j] = k;
        }
}

int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A)
{
    int minValue = INF, value;
    for (int k = i; k <= j; k++) {
        value = A[i][k - 1] + A[k + 1][j];
        if (minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    for (int m = i; m <= j; m++)
        minValue += p[m];
    return minValue;
}

void print(int n, matrix_t& m)
{
    for (int i = 1; i <= n + 1; i++) {
        cout << m[i][i - 1];
        for (int j = i; j <= n; j++)
            cout << ' ' << m[i][j];
        cout << '\n';
    }
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R)
{
    int k = R[i][j];
    if (k == 0)
        return NULL;
    else {
        node_ptr node = create_node(keys[k]);
        node->left = tree(i, k - 1, keys, R);
        node->right = tree(k + 1, j, keys, R);
        return node;
    }
}

node_ptr create_node(int key)
{
    node_ptr n = (node_ptr)malloc(sizeof(node));
    n->key = key;
    return n;
}

void preorder(node_ptr t, vector<int>& res)
{
    if (t != NULL) {
        res.push_back(t->key);
        preorder(t->left, res);
        preorder(t->right, res);
    }
}

void inorder(node_ptr t, vector<int>& res)
{
    if (t != NULL) {
        inorder(t->left, res);
        res.push_back(t->key);
        inorder(t->right, res);
    }
}

void printres(vector<int>& res)
{
    if (res.size() > 0) {
        cout << res[0];
        for (int i = 1; i < res.size(); i++)
            cout << ' ' << res[i];
        cout << '\n';
    }
}