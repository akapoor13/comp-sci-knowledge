#include <stdio.h>

class BST {
    class Node {
        int data;
        Node *left;
        Node *right;

        Node(int d): data{d} {};
    };

    Node* root = nullptr;

    Node* insertNodeR(Node* root, int value) {
        if (root==nullptr) {
            return Node(value);
        } else if ((root->data)>value) {
            root->left = insertNodeR(root->left, value);
        } else {
            root->right = insertNodeR(root->right, value);
        }
        
        return root;
    }

    void insertNode(Node* root, int value) {
        root = insertNoder(root, value);
    }

    Node* copyBSTr(Node* copyIntoRoot, Node* root2) {
        if (root2==nullptr) {
            return copyIntoRoot;
        } else {
            insertNode(copyIntoRoot, root2->data);
            copyBST(copyIntoRoot, root2->left);
            copyBST(copyIntoRoot, root->right);
        }

        return copyIntoRoot
    }

    void copyBST(Node* root2) {
        root = copyBSTr(root, root2);
    }
};

int main() {
    return 1;
}