#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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
void LevelOrderInSpiralForm(Node* root,vector<int>&result){
    if (root == NULL) return;
    stack<Node*>st1;    //right to left
    stack<Node*>st2;    //left to right
    int turn;
    cout<<"Enter 1 if you want to start from right to left and 0 if you want to start form left to right"<<endl;
    cin>>turn;
    if(turn==1){
        st1.push(root);
    }
    else{
        st2.push(root);
    }
    
    while(!st1.empty() || !st2.empty()){
        if(turn==1){        //turn ==1 means elements right se left insert honge 2nd stack mai..
            while(!st1.empty()){
                Node* temp=st1.top();
                st1.pop();
                result.push_back(temp->data);
                if(temp->right){
                    st2.push(temp->right);
                }
                if(temp->left){
                    st2.push(temp->left);
                }
                turn=0;
            }
        }
        else{               //turn ==0 means elements left se right insert honge 1st stack mai..
            while(!st2.empty()){
                Node* temp=st2.top();
                st2.pop();
                result.push_back(temp->data);
                if(temp->left){
                    st1.push(temp->left);
                }
                if(temp->right){
                    st1.push(temp->right);
                }
                turn=1;
            }
        }
    }
}
int main(){
    cout<<"Enter the rootNode"<<endl;
    Node* root=BinaryTree();
    vector<int>result;
    LevelOrderInSpiralForm(root,result);
    cout<<"Levelorder Traversal in spiral form of the input BT is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}