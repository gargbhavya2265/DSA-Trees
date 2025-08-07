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
int heightBT(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(heightBT(root->left),heightBT(root->right));
}
void leftViewBT(Node* root,vector<int>&result,vector<int>&levelvisited,int level){
    if(root==NULL)  return;
    // if(level==result.size()){
    //     result.push_back(root->data);
    // }
    if(levelvisited[level]==0){
        result.push_back(root->data);
        levelvisited[level]=1;
    }
    leftViewBT(root->left,result,levelvisited,level+1);
    leftViewBT(root->right,result,levelvisited,level+1);

}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();
    vector<int>result;
    int height=heightBT(root);
    vector<int>levelvisited(height,0);
    leftViewBT(root,result,levelvisited,0);
    cout<<"LeftView Of BT is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}