#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;

map<int, int> visited;
map<int, char> color;
map<int, vector<int> > graph;

void bfs(int src, map<int, vector<int> > graph){

    queue<int> q;
    q.push(src);
    visited[src]=1;
    color[src]='R';

    while(!q.empty()){
        int u = q.front();
        q.pop();

        int n = graph[u].size();

        for(int i=0;i<n;i++){
            int v = graph[u][i];
            if(visited[v]==-1){
                visited[v]=visited[u]+1;
                //setting color
                if(color[u]=='R'){
                    color[v]='Y';
                }
                else if(color[u]=='Y'){
                    color[v]='R';
                }

                q.push(v);
            }
        }

    }

}

bool checkBicolor(int n){
    int i,j;
    for(i=0;i<n;i++){
        //char clr = color[i];
        int n = graph[i].size();

        for(j=0;j<n;j++){
            int v = graph[i][j];
            if(color[v]==color[i]){
                return true;
            }
        }

    }

    return false;

}


int main(){

   //it was my logic.it is good
   //but u can code it in a very formal way
   //it's also accepted.
   int n,e,i,n1,n2;

   while(cin>>n){
        if(n==0){
            break;
        }

        cin>>e;
        //map<int, vector<int> > graph;
        graph.clear();
        visited.clear();
        color.clear();

        for(i=1;i<=e;i++){
            cin>>n1>>n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);

            visited[n1]=-1;
            visited[n2]=-1;
        }

        bfs(0,graph);
        bool flag = checkBicolor(n);

        if(!flag){
            printf("BICOLORABLE.\n");
        }
        else{
            printf("NOT BICOLORABLE.\n");
        }

   }

    return 0;
}
