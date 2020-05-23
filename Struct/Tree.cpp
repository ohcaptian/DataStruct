//
// Created by 17694 on 2020/5/23.
//
/*
 * 二叉树的生成与遍历
 */
#include <iostream>
using namespace std;
#include<stack>
typedef struct TreeNode{
    int data;
    TreeNode *left,*right;
}Node,*ptrtree;
void CreateTree_pre(ptrtree &root);
void TravelTree_pre(ptrtree root);
void TravelTree_in(ptrtree root);
void TravleTree_Post(ptrtree root);
void TravelTree_inorderwithourcur(ptrtree root);
void TravelTree_prewithourcur(ptrtree root);
int main(){
        ptrtree root;
    CreateTree_pre(root);
    cout<<"二叉树的前序遍历";
    TravelTree_pre(root);
    cout<<endl;
    cout<<"二叉树的中序遍历";
    TravelTree_in(root);
    cout<<endl;
    cout<<"二叉树的后序遍历";
    TravleTree_Post(root);
    cout<<endl;
    cout<<"二叉树的中序非递归遍历";
    TravelTree_inorderwithourcur(root);
    cout<<endl;        
    cout<<"二叉树的前序非递归遍历";
    TravelTree_prewithourcur(root);
}
void CreateTree_pre(ptrtree &root){
    char ch;
    cin>>ch;
    if(ch=='#'){
        root = NULL;
        return;
    }
    root = new Node ();
    if(!root){
        cout<<"ERROR"<<endl;
        return;
    }
    root->data=ch-'0';
    CreateTree_pre(root->left);
    CreateTree_pre(root->right);
}
void TravelTree_pre(ptrtree root){
            if(!root){
                return;
            }
            cout<<root->data<<" ";
            TravelTree_pre(root->left);
            TravelTree_pre(root->right);
}
void TravelTree_in(ptrtree root){
    if(!root){
        return;
    }
    TravelTree_in(root->left);
    cout<<root->data<<" ";
    TravelTree_in(root->right);
}
void TravleTree_Post(ptrtree root){
    if(!root){
        return;
    }
    TravelTree_in(root->left);
    TravelTree_in(root->right);
    cout<<root->data<<"";
}
void TravelTree_inorderwithourcur(ptrtree root){
        ptrtree temp =root;
    if(!root){
        cout<<"Tree is empty"<<endl;
        return;
    }
    stack<ptrtree> st;
        while(!st.empty()||temp){
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
            if (!st.empty()) {
                temp = st.top();
                st.pop();
                cout << temp->data<<" ";
                temp = temp->right;
            }
        }
}
void TravelTree_prewithourcur(ptrtree root){
                 ptrtree temp = root;
            stack<ptrtree> st;
            if(!root){
                cout<<"Tree is empty"<<endl;
                return;
            }
            while(temp||!st.empty()) {
                while (temp) {
                    st.push(temp);
                    cout << temp->data << " ";
                    temp = temp->left;
                }
                temp = st.top();
                st.pop();
                temp = temp->right;
            }
}