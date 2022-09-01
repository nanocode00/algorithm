#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <map>
using namespace std;

typedef struct node* node_ptr;
typedef struct node {
    char symbol;
    int frequency;
    node_ptr left;
    node_ptr right;
} node_t;

struct compare {
    bool operator()(node_ptr p, node_ptr q) {
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<node_ptr, vector<node_ptr>, compare> PrirorityQueue;

void huffman(int n, PrirorityQueue& PQ);
node_ptr create_node(char c, int freq);
void make_decoder(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder);
void encode(string to_encode, string& res, vector<char> c, map<char, vector<int>> decoder);
void decode(string to_decode, string& res, node_ptr root);
void preorder(node_ptr root, vector<string>& res);
void inorder(node_ptr root, vector<string>& res);
void print_res(vector<string> res);

int main()
{
    int n, T1, T2;
    string r;
    vector<char> c;
    vector<int> freq, code;
    vector<string> res, to_encode, to_decode;
    map<char, vector<int>> decoder;
    node_ptr root;
    PrirorityQueue PQ;

    cin >> n;
    c = vector<char>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    freq = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> freq[i];
    }
    for (int i = 1; i <= n; i++) {
        PQ.push(create_node(c[i], freq[i]));
    }

    cin >> T1;
    to_encode = vector<string>(T1);
    for (int i = 0; i < T1; i++) {
        cin >> to_encode[i];
    }
    
    cin >> T2;
    to_decode = vector<string>(T2);
    for (int i = 0; i < T2; i++) {
        cin >> to_decode[i];
    }

    huffman(n, PQ);
    root = PQ.top();
    PQ.pop();
    make_decoder(root, code, decoder);

    preorder(root, res);
    print_res(res);
    res.clear();

    inorder(root, res);
    print_res(res);
    res.clear();

    for (int i = 0; i < T1; i++) {
        encode(to_encode[i], r, c, decoder);
        cout << r << '\n';
        r.clear();
    }

    for (int i = 0; i < T2; i++) {
        decode(to_decode[i], r, root);
        cout << r << '\n';
        r.clear();
    }
}

void huffman(int n, PrirorityQueue& PQ)
{
    for (int i = 1; i <= n - 1; i++) {
        node_ptr p = PQ.top(); PQ.pop();
        node_ptr q = PQ.top(); PQ.pop();
        node_ptr r = create_node('+', p->frequency + q->frequency);
        r->left = p;
        r->right = q;
        PQ.push(r);
    }
}

node_ptr create_node(char c, int freq)
{
    node_ptr n = (node_ptr)malloc(sizeof(node));
    n->symbol = c;
    n->frequency = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void make_decoder(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder)
{
    if (root != NULL) {
        if (root->symbol != '+') {
            vector<int> ret;
            ret.resize(code.size());
            copy(code.begin(), code.end(), ret.begin());
            decoder.insert(make_pair(root->symbol, ret));
        } else {
            code.push_back(0);
            make_decoder(root->left, code, decoder);
            code.pop_back();
            code.push_back(1);
            make_decoder(root->right, code, decoder);
            code.pop_back();
        }
    }
}

void encode(string to_encode, string& res, vector<char> c, map<char, vector<int>> decoder)
{
    for (int i = 0; i < to_encode.size(); i++) {
        for (int j = 1; j < c.size(); j++) {
            if (c[j] == to_encode[i]) {
                vector<int> temp = decoder[c[j]];
                for (int k = 0; k < temp.size(); k++) {
                    res += to_string(temp[k]);
                }
                break;
            }
        }
    }
}

void decode(string to_decode, string& res, node_ptr root)
{
    node_ptr n = root;
    for (int i = 0; i < to_decode.size(); i++) {
        if (to_decode[i] == '0') {
            n = n->left;
        } else {
            n = n->right;
        }
        if (n->left == NULL && n->right == NULL) {
            res += n->symbol;
            n = root;
        }
    }
}

void preorder(node_ptr root, vector<string>& res)
{
    if (root != NULL) {
        res.push_back(string() + root->symbol + ':' + to_string(root->frequency));
        preorder(root->left, res);
        preorder(root->right, res);
    }
}

void inorder(node_ptr root, vector<string>& res)
{
    if (root != NULL) {
        inorder(root->left, res);
        res.push_back(string() + root->symbol + ':' + to_string(root->frequency));
        inorder(root->right, res);
    }
}

void print_res(vector<string> res)
{
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}