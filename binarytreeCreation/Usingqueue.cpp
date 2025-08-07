#include<iostream>
#include<queue>
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
int main(){
    int rootnode_data,leftchild_data,rightchild_data;
    cout<<"enter the root node"<<endl;
    cin>>rootnode_data;
    Node* root=new Node(rootnode_data);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->data<<endl;
        cin>>leftchild_data;
        if(leftchild_data!=-1){
            temp->left=new Node(leftchild_data);
            q.push(temp->left);
        }

        cout<<"Enter the right child of "<<temp->data<<endl;
        cin>>rightchild_data;
        if(rightchild_data!=-1){
            temp->right=new Node(rightchild_data);
            q.push(temp->right);
        }
    }
    cout<<"Binary tree creation donee..."<<endl;
}