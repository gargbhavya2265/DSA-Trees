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
int countLeaves(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return countLeaves(root->left)+countLeaves(root->right);
}
int main(){
    cout<<"Enter the root Node"<<endl;
    Node* root=BinaryTree();
    int count=countLeaves(root);
    if(count==0){
        cout<<"There is no node in the hierarchy.."<<endl;
    }
    else{
        cout<<"No of leavesNodes are: "<<count<<endl;
    }
}