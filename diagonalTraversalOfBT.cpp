#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
Node* BTCreation(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node* temp=new Node(x);
    cout<<"Enter the leftchild of :"<<x<<endl;
    temp->left=BTCreation();
    cout<<"Enter the rightchild of :"<<x<<endl;
    temp->right=BTCreation();

    return temp;

}
void findLeftMost_RightMost_Node_pos(Node* root,int &l,int &r,int pos){
    if(root==NULL)  return;
    l=min(l,pos);
    r=max(r,pos);
    findLeftMost_RightMost_Node_pos(root->left,l,r,pos-1);
    findLeftMost_RightMost_Node_pos(root->right,l,r,pos+1);
}
void topView(Node* root,int l,int r,vector<vector<int>>& helper){
    if(root==NULL)  return ;
    helper[l].push_back(root->data);
    topView(root->left,l+1,r,helper);
    topView(root->right,l,r+1,helper);
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BTCreation();
    int l=0,r=0,pos=0;
    findLeftMost_RightMost_Node_pos(root,l,r,pos);
    vector<vector<int>>helper(abs(l)+1);
    topView(root,0,0,helper);
    cout<<"Top View Of BT Is: "<<endl;
    for(int i=0;i<helper.size();i++){
        for(int j=0;j<helper[i].size();j++){
            cout<<helper[i][j]<<" ";
        }
    }
}