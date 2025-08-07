#include<iostream>
#include<vector>
#include<climits>
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
void findposition(Node* root,int &l,int &r,int pos){
    if(!root)   return ;
    l=min(l,pos);
    r=max(r,pos);
    findposition(root->left,l,r,pos-1);
    findposition(root->right,l,r,pos+1);
}
void topViewRecursive(Node* root,vector<int>& level,vector<int>& result,int pos,int l){
    if(!root) return;
    if(level[pos]>l){
        level[pos]=l;
        result[pos]=root->data;
    }
    topViewRecursive(root->left,level,result,pos-1,l+1);
    topViewRecursive(root->right,level,result,pos+1,l+1);

}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();
    int l=0,r=0;
    findposition(root,l,r,0);
    vector<int>level(r-l+1,INT_MAX);
    vector<int>result(r-l+1);
    topViewRecursive(root,level,result,-1*l,0);
    cout<<"top View of BT is: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

}