#include <iostream>
using namespace std;



class BST
{
    
    class Node
    {
        public:
            int data;
            Node *left;
            Node* right;

            Node(int data) : data{data}, left{nullptr}, right{nullptr} {};
            
    };
    Node *root = nullptr;
    

    public:
        void insert(int v)
        {
            root=insertNodeR(root,v);
        }
        
        Node *insertNodeR(Node *root, int value)
        {
            if (root == nullptr)
            {
                return new Node(value);
            }
            else if ((root->data) > value)
            {
                root->left = insertNodeR(root->left, value);
            }
            else
            {
                root->right = insertNodeR(root->right, value);
            }
    
            return root;
        }
    
        Node *copyBSTr( Node *root2)
        {
            if (root2 == nullptr)
            {
                return nullptr;
            }
            else
            {
                Node *r =new Node(root2->data);
                r->left =copyBSTr(root2->left);
                r->right =copyBSTr(root2->right);
                return r;
            }
        }
    
        void copy(BST t2)
        {
            root = copyBSTr(t2.root);
        }
        
        void inorderR(Node* root) {
            if (root==nullptr) {
                return;
            } else {
                inorderR(root->left);
                cout << root->data<<"\t";
                inorderR(root->right);
            }
        }
        
        void inorder() {
            inorderR(root);
        }
        
        void mirrorR(Node* root) {
            if (root==nullptr) {
                return;
            } else {
                Node *temp = root->left;
                root->left = root->right;
                root->right = temp;
                
                mirrorR(root->left);
                mirrorR(root->right);
            }
        }
        
        void mirror() {
            mirrorR(root);
        }
};



int main()
{
   
   BST x,y;
   x.insert(50);
   x.insert(70);
   x.insert(90);
   x.insert(150);
   x.insert(175);
   x.insert(25);
   y.copy(x);
   y.inorder();
   x.mirror();
   x.inorder();
}