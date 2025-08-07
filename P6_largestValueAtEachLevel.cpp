#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<limits.h>
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
void largestValue(Node* root,vector<int>&result){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int maxval=INT_MIN;
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            maxval=max(maxval,temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        result.push_back(maxval);
    }
}
int main(){
    cout<<"Enter the root Node"<<endl;
    vector<int>result;
    Node* root=BinaryTree();
    largestValue(root,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}