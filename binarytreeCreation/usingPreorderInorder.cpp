#include<iostream>
#include<vector>
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
void PREORDER(Node* root){
    //base case..
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    PREORDER(root->left);
    PREORDER(root->right);
}
void INORDER(Node* root){
    if(root==NULL){
        return ;
    }
    INORDER(root->left);
    cout<<root->data<<" ";
    INORDER(root->right);
}
void POSTORDER(Node* root){
    if(root==NULL){
        return ;
    }
    POSTORDER(root->left);
    POSTORDER(root->right);
    cout<<root->data<<" ";
}
int findPosition(vector<int>&inorder,int key){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==key){
            return i;
        }
    }
    return -1;
}
Node* BTCreation(vector<int>&inorder,vector<int>& preorder,int instart,int inend,int index){
    if(instart>inend){
        return NULL;
    }
    Node* root=new Node(preorder[index]);
    int pos=findPosition(inorder,preorder[index]);
    root->left=BTCreation(inorder,preorder,instart,pos-1,index+1);
    root->right=BTCreation(inorder,preorder,pos+1,inend,index+(pos-instart)+1);
    return root;
}
int main(){
    int n;
    cout<<"Enter the total Number of Nodes"<<endl;
    cin>>n;
    vector<int>preorder(n);
    vector<int>inorder(n);
    cout<<"Enter the Preorder:"<<endl;
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    cout<<"Enter the Inorder:"<<endl;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    cout<<"\npreorder is: ";
    for(int i=0;i<n;i++){
        cout<<preorder[i]<<" ";
    }
    cout<<"\npreorder is: ";
    for(int i=0;i<n;i++){
        cout<<inorder[i]<<" ";
    }
    int instart=0,inend=n-1,index=0;
    Node* root=BTCreation(inorder,preorder,instart,inend,index);

    cout<<"\nverify if the preorder and inorder input matches with inorder and preorder output?????"<<endl;
    cout<<"Preorder Traversal of Binary Tree is: ";
    PREORDER(root);
    cout<<endl;
    cout<<"Inorder Traversal of Binary Tree is: ";
    INORDER(root);
    cout<<endl;
    cout<<"Postorder Traversal of Binary Tree is: ";
    POSTORDER(root);
    cout<<endl;
}