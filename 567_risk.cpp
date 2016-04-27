#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int visited[23];

int bfs(int start, int to, map<int, vector<int> > graph){

    queue<int> q;
    q.push(start);
    visited[start]=0;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(to==top){
            return visited[top];
        }
        int n = graph[top].size();
        for(int i=0;i<n;i++){
            int v = graph[top][i];
            if(visited[v]==-1){
                visited[v]=visited[top]+1;
                q.push(v);
            }

        }

    }
}

int main(){

    //Accepted
    int i,num,start,to,n,tc=0,j,numI;
    i=1;
    map<int, vector<int> > graph;

    while(scanf("%d",&numI)!=EOF){

        for(j=0;j<numI;j++){
            scanf("%d",&num);
            graph[i].push_back(num);
            graph[num].push_back(i);
        }
        //the 20th line.
        if(i==19){
            scanf("%d",&n);
            printf("Test Set #%d\n",++tc);
            for(j=0;j<n;j++){
                memset(visited,-1,sizeof(visited));
                scanf("%d%d",&start,&to);
                printf("%2d to %2d: %d\n",start,to,bfs(start,to,graph));
            }

            graph.clear();
            i=0;
            printf("\n");
        }

        i++;

    }

    return 0;
}
