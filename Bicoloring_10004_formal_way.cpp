#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main(){

    //Accepted
    int n,e,i,n1,n2;

    while(cin>>n){
        if(n==0){
            break;
        }

        map<int, vector<int> > graph;
        map<int, int> visited;
        map<int, char> color;

        cin>>e;

        for(i=1;i<=e;i++){
            cin>>n1>>n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);

            visited[n1]=-1;
            visited[n2]=-1;
        }

        queue<int> q;
        int f=0;
        q.push(0);
        visited[0]=1;
        color[0]='R';

        while(!q.empty()){
            int u = q.front();
            q.pop();

            int n = graph[u].size();
            for(i=0;i<n;i++){
                int v = graph[u][i];
                if(visited[v]==-1){
                    visited[v]=visited[u]+1;

                    if(color[u]=='R'){
                        color[v]=='Y';
                    }
                    else{
                        color[v]='R';
                    }

                    q.push(v);
                }
                else{
                    if(color[v]==color[u]){
                        f=1;
                        break;
                    }
                }
            }

            if(f==1){
                break;
            }

        }

        if(f==1){
            printf("NOT BICOLORABLE.\n");
        }
        else{
            printf("BICOLORABLE.\n");
        }

    }

    return 0;
}
