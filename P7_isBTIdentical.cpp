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
bool isIdentical(Node* r1,Node* r2){
    if(r1==NULL && r2==NULL){
        return 1;
    }
    if((r1!=NULL && r2==NULL)||(r1==NULL && r2!=NULL)){
        return 0;
    }
    if(r1->data!=r2->data){
        return 0;
    }
    // if(!(isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right))){
    //     return 0;
    // }
    return (isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right));
}
int main(){
    cout<<"Enter the rootNode of first BT"<<endl;
    Node* root1=BinaryTree();
    cout<<"Enter the rootNode of second BT"<<endl;
    Node* root2=BinaryTree();

    bool result=isIdentical(root1,root2);
    if(result){
        cout<<"Both Trees are identical"<<endl;
    }
    else{
        cout<<"Both the trees are not identical"<<endl;
    }
    return 0;
}