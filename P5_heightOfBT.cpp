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
    Node *temp=new Node(x);
    cout<<"Enter the leftchild of "<<x<<endl;
    temp->left=BinaryTree();
    cout<<"Enter the rightchild of "<<x<<endl;
    temp->right=BinaryTree();

    return temp;
}
//if height is considered as the no of nodes..
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return 1+max(height(root->left),height(root->right));
}
//if height is considered as the number of edges..
int heightBT(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    return 1+max(heightBT(root->left),heightBT(root->right));
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();

    int nodes=height(root);
    cout<<" Height of BT(no of nodes) is: "<<nodes<<endl;

    int edges=heightBT(root);
    cout<<" Height of BT(no of edges) is: "<<edges<<endl;
}