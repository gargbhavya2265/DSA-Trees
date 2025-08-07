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

int countNonLeaves(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    return 1+countNonLeaves(root->left)+countNonLeaves(root->right);
}
int main(){
    cout<<"Enter the root Node"<<endl;
    Node* root=BinaryTree();
    int count=countNonLeaves(root);
    cout<<"Number of nonLeaves Nodes are: "<<count<<endl;
    

}