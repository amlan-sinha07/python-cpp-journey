#include <iostream>
#include <algorithm>
using namespace std;
class Node{
    public:
    int value;
    Node* right;
    Node* left;
    Node (int v){
        value=v;
        left=nullptr;
        right=nullptr;
    }
};
class BST{
    public:
    Node* root;
    BST(){
        root=nullptr;
    }
    void insert(int value){
        if (root==nullptr){
            root=new Node(value);
        }
        else {
            insertHelper(root,value);
        }
    }
    void insertHelper(Node* node,int value){
        if (value<node->value){
            if (node->left==nullptr){
                node->left=new Node(value);
            } else {
                insertHelper(node->left,value);
            }
        } else {
            if (node->right==nullptr){
                node->right=new Node(value);
            } else {
                insertHelper(node->right,value);
            }
        }
    }
    bool search(Node* node,int value){
        if (node == nullptr){
            cout<<"value not found"<<endl;
            return false;
        }
        if (node->value==value){
            cout<<"value found"<<endl;
            return true;
        }
        else if (node->value<value){
            return search(node->right,value);
        }
        else {
            return search(node->left,value);
        }
    }
    void inorder(Node* node){
        if (node != nullptr){
            inorder(node->left);
            cout<<node->value<<endl;
            inorder(node->right);
        }
    }
    int height(Node* node){
        if (node == nullptr){
            return 0;
        }
        return 1+ max(height(node->right),height(node->left));
    }
};
int main(){
    BST tree;
    int values[]={8,5,7,4,3,10,1,6,14,99,50,11};
    for (int v:values){
        tree.insert(v);
    }
    cout<<"root: "<<tree.root->value<<endl;
    cout<<"root->left: "<<tree.root->left->value<<endl;
    cout<<"root->right: "<<tree.root->right->value<<endl;

    cout<<tree.search(tree.root,6)<<endl;
    cout<<tree.search(tree.root,9)<<endl;

    tree.inorder(tree.root);
    cout<<endl;

    cout<<"height: "<<tree.height(tree.root)<<endl;

    return 0;
}