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
int sumBT(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->data+sumBT(root->left)+sumBT(root->right);
}
int main(){
    cout<<"Enter the root node"<<endl;
    Node* root=BinaryTree();

    int sum=sumBT(root);
    cout<<"Sum of all nodes of BT is: "<<sum<<endl;
}