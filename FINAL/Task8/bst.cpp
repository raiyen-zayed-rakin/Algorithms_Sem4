#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node() {
        value = 0;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    void insert(int v, Node* &root) {
        if (root == NULL) {
            Node* nn = new Node();
            nn->value = v;
            root = nn;
            cout << "Value added : " << v << endl;
        } else {
            if (v < root->value) {
                insert(v, root->left);
            } else {
                insert(v, root->right);
            }
        }
    }

    bool search(int v, Node* root) {
        if (root == NULL) {
            return false; 
        }
        if (root->value == v) {
            return true; 
        }
        if (v < root->value) {
            return search(v, root->left); 
        } else {
            return search(v, root->right); 
        }
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->value << " -> ";
            inorder(root->right);
        }
    }
    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->value << " -> ";
            preorder(root->left);
            preorder(root->right);
        }
    }
};

int main() {
    BST bst;

    bst.insert(2, bst.root);
    bst.insert(4, bst.root);
    bst.insert(5, bst.root);
    bst.insert(6, bst.root);
    bst.insert(7, bst.root);
    bst.insert(9, bst.root);

    cout << "Inorder Traversal: ";
    bst.inorder(bst.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    bst.preorder(bst.root);
    cout << endl;
    
    cout<<"Enter value to search in the BST : ";
    int value;
    cin>>value;
    if (bst.search(value, bst.root)) {
        cout << value << " found in the BST." << endl;
    } else {
        cout << value << " not found in the BST." << endl;
    }

    return 0;
}
