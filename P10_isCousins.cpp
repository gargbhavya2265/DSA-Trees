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
bool isParentSame(Node* root,int x,int y){
    if(root==NULL){
        return 0;
    }
    if(root->left && root->right){
        if((root->left->data==x && root->right->data==y)||(root->left->data==y && root->right->data==x)){
            return 1;
        }
    }
    return (isParentSame(root->left,x,y) || isParentSame(root->right,x,y));
}
bool isCousins(Node* root,int x,int y){
    if(root == NULL) return false;
    queue<Node*>q;
    q.push(root);
    bool lx=0;
    bool ly=0;
    while(!q.empty()){
        int  n=q.size();
        while(n--){
            Node* temp=q.front();
            q.pop();
            if(temp->data==x) lx=1;
            if(temp->data==y)  ly=1;

            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(lx && ly){
            return (!isParentSame(root,x,y));
        }
        if(lx || ly)    return 0;
    }
    return false;
}
int main(){
    cout<<"Enter the rootnode"<<endl;
    Node* root=BinaryTree();
    int x,y;
    cout<<"Enter the nodes you want to check whether they are cousins or not"<<endl;
    cin>>x;
    cin>>y;

    bool iscousins=isCousins(root,x,y);
    if(iscousins){
        cout<<x<<" and "<<y<<" are cousins"<<endl;
    }
    else{
        cout<<x<<" and "<<y<<" are not cousins"<<endl;
    }
}