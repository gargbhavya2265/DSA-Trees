#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    //constructor..
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
Node* BinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node* temp=new Node(x);
    cout<<"Enter the leftchild of "<<x<<endl;
    temp->left=BinaryTree();
    cout<<"Enter the right child of "<<x<<endl;
    temp->right=BinaryTree();

    return temp;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node* root){
    if(root==NULL){
        return 1;
    }
    int hl=height(root->left);
    int hr=height(root->right);
    if(abs(hl-hr)>1){
        return 0;
    }
    return isBalanced(root->left)&& isBalanced(root->right);
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();

    bool isbalanced=isBalanced(root);
    if(isbalanced){
        cout<<"BT is Balanced"<<endl;
    }
    else{
        cout<<"BT is not Balanced"<<endl;
    }
}