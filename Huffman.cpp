#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define ll long long

int N;
map<string, int> chars;
int total;

int fixed_length_code;
int huffman_code;

class node {
public:
    string chars;
    int nums;
    node* left;
    node* right;
    int count;

    node() {
        chars = "";
        nums = 0;
        left = NULL;
        right = NULL;
        count = 0;
    }

    node& operator=(const node& A) {

        this->chars = A.chars;
        this->nums = A.nums;
        this->left = A.left;
        this->right = A.right;
        this->count = A.count;

        return *this;
    }
};
class compare {
public:
    bool operator()(node* a, node* b) {
        if (a->nums > b->nums) {
            return true;
        }
        return false;
    }
};
priority_queue<node*, vector<node*>, compare > nodeheap;

void calhuff(node* n, int count);

int main() {

    //입력받기
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string a;
        int b;
        cin >> a >> b;

        chars.insert(make_pair(a, b));
    }
    cin >> total;

    //fixed-length-code 구하기
    int bits = 1;
    int temp = N;
    while (temp = temp / 2) {
        bits++;
    }
    fixed_length_code = bits * total;

    //Huffman_code 구하기
    for (map<string, int>::iterator i = chars.begin(); i != chars.end(); i++) {
        //모든 알파벳 heap에 때려넣기
        node* tmp = new node();
        tmp->chars = i->first;
        tmp->nums = i->second;

        nodeheap.push(tmp);
    }

    node* root = NULL;
    while (nodeheap.size() != 1) {
        node* a = nodeheap.top();
        nodeheap.pop();
        node* b = nodeheap.top();
        nodeheap.pop();

        node* compound = new node();
        compound->nums = a->nums + b->nums;
        compound->left = a;
        compound->right = b;
        nodeheap.push(compound);
    }
    root = nodeheap.top();
    calhuff(root, 0);

    cout << fixed_length_code << "\n" << huffman_code << "\n";

    return 0;
}

void calhuff(node* n, int count) {
    if (n == NULL) {
        //cout << "No node!\n";
        return;
    }

    n->count = count;
    if (n->chars != "") {
        huffman_code += chars[n->chars] * n->count;
        return;
    }
    else {
        calhuff(n->left, count + 1);
        calhuff(n->right, count + 1);
    }
}