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
    cout<<"Enter the rightchild of "<<x<<endl;
    temp->right=BinaryTree();

    return temp;
}
void preorder(Node* temp){
    if(temp==NULL){
        return ;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
void swap(Node* &left,Node* &right){
    Node* temp=left;
    left=right;
    right=temp;
}
Node* convertMirrorTree(Node* root){
    if(root==NULL){
        return NULL;
    }
    swap(root->left,root->right);
    convertMirrorTree(root->left);
    convertMirrorTree(root->right);

    return root;
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();
    cout<<"Preorder before conversion: ";
    preorder(root);
    root=convertMirrorTree(root);
    cout<<"\nPreorder after conversion: ";
    preorder(root);

}