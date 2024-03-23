#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct compareNodes {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void generateCodes(Node* root, string code, string codes[]) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        codes[root->data - 'a'] = code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

void huffmanCoding(int freq[], string codes[]) {
    priority_queue<Node*, vector<Node*>, compareNodes> pq;
    for (int i = 0; i < 6; ++i) {
            pq.push(new Node('a' + i, freq[i]));
    }
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    Node* root = pq.top();
    generateCodes(root, "", codes);
}

int main() {
    int freq[6];
    cout << "Enter frequencies for characters 'a' to 'f':\n";
    for (int i = 0; i < 6; ++i) {
        char ch = 'a' + i;
        cout << ch << ": ";
        cin >> freq[i];
    }

    string codes[26];
    huffmanCoding(freq, codes);

    cout << "Variable length codes:\n";
    for (int i = 0; i < 6; ++i) {
        if (!codes[i].empty())
            cout << char('a' + i) << ": " << codes[i] << endl;
    }
    return 0;
}
