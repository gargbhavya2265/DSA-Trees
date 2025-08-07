#include<iostream>
#include<vector>
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
void leftViewBT(Node* root,vector<int>&result)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        result.push_back(q.front()->data);
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();
    vector<int>result;
    leftViewBT(root,result);
    cout<<"LeftView Of BT is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}