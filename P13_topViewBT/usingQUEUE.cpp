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
void findleftmost_rightmost_Nodes_pos(Node* root,int &l,int &r,int pos){
    if(root==NULL)  return;
    l=min(l,pos);
    r=max(r,pos);
    findleftmost_rightmost_Nodes_pos(root->left,l,r,pos-1);
    findleftmost_rightmost_Nodes_pos(root->right,l,r,pos+1);
}
void levelOrderTraversal(Node* root,vector<int>&result,vector<bool>&filled,int l){
    queue<Node*>q;
    queue<int>index;
    q.push(root);
    index.push(-l);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        int position=index.front();
        index.pop();
        if(filled[position]==0){
            filled[position]=1;
            result[position]=temp->data;
        }
        if(temp->left){
            q.push(temp->left);
            index.push(position-1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(position+1);
        }
    }
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();
    int l=0,r=0;
    findleftmost_rightmost_Nodes_pos(root,l,r,0);
    int size=r-l+1;
    vector<int>result(size);
    vector<bool>filled(size,0);
    levelOrderTraversal(root,result,filled,l);
    cout<<"TopView of BT is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}