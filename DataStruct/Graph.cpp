//
// Created by 17694 on 2020/5/27.
//
/*
 * des 邻接矩阵的遍历和生成
 */
#include<iostream>
using namespace std;
typedef  int Status;
typedef int ArcType;// Arc  weight
typedef char VerTexType;// Ver datatype
#define MaxInt 32767
#define MvNum 100 //Max number of Ver;
#include <queue>
/*
*
 4 2
a b c d
a b 1
a c 1
 */
typedef struct Graph{
    VerTexType vers[MvNum];
    ArcType acrs[MvNum][MvNum];
    int vexnum,arcnum;
}AMGraph;
bool visited[MvNum]={ 0 };//DFS 标志数组;
Status CreateGraph(AMGraph &G);
void DFS(AMGraph G,int v);//递归遍历邻接矩阵;
void BFS(AMGraph G,int i);//广度优先搜索
int main(){

        AMGraph G;
        CreateGraph(G);
        int v=0;
        DFS(G,v);
        cout<<endl;
        BFS(G,v);
}
int LocateVex(AMGraph G,char v);
Status CreateGraph(AMGraph &G){
    char v1,v2;
    int w;
    //cout<<"vexnum and arcnum"<<endl;
    cin>>G.vexnum>>G.arcnum;//顶点数和边数;
    //cout<<"VerTex"<<endl;
    for(int i=0;i<G.vexnum;i++){
        cin>>G.vers[i];
    }
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;++j){
            G.acrs[i][j]=0;
        }
    }
    //cout<<"arc and weight";
    for(int k=0;k<G.arcnum;k++){
        cin>>v1>>v2; //确定一条边
        cin>>w;
        int i=LocateVex(G,v1);
        int j=LocateVex(G,v2);
        G.acrs[i][j]=w;
        G.acrs[j][i]=G.acrs[i][j];
    }
    return 0;
}
int LocateVex(AMGraph G,char v){
    int n=G.vexnum;//遍历查找顶点
   for(int i=0;i<G.vexnum;i++){
       if(G.vers[i]==v) {
           return i;
       }
}
    cout<<"ERROR"<<endl;
    return -1;
}
//v  默认使用第一个结点;
void DFS(AMGraph G,int i){
    cout<<G.vers[i];visited[i]= true;
    for(int w=0;w<G.vexnum;w++){
        if((G.acrs[i][w]!=0)&&(!visited[w])){
            DFS(G,w);
        }
    }
};
void BFS(AMGraph G,int i){
    int visited[G.vexnum];
    for(int i=0;i<G.vexnum;i++){
        visited[i]= false;
    }
        queue<char> qg;
        qg.push(G.vers[i]);
        while(!qg.empty()){
            char temp = qg.front();
            qg.pop();
            i= LocateVex(G,temp);
            cout<<temp;visited[i]=true;
            for(int w=0;w<G.vexnum;w++){
                if((G.acrs[i][w]!=0)&&(!visited[w])){
                        qg.push(G.vers[w]);
                }
            }
       }
}
