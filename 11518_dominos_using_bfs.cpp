#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define CLR(a) memset(a, 0, sizeof(a))
#define MX 10003

int n;
vector<int> graph[MX];
int visited[MX];
int cnt;

void bfs(int src){

    queue<int> q;
    q.push(src);

    if(!visited[src]){
       visited[src]=1;
       ++cnt;
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();

        int n = graph[top].size();
        for(int i=0;i<n;i++){
            int v = graph[top][i];
            if(!visited[v]){
                visited[v]=1;
                ++cnt;
                q.push(v);
            }
        }
    }

    /*
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            ++cnt;
        }
    }

    printf("%d\n",cnt);
    */
}


void clear_graph(){
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
}


int main(){

    //Accepted
    int m,l,tc,i,x,y;

    scanf("%d",&tc);
    while(tc--){

        scanf("%d%d%d",&n,&m,&l);

        clear_graph();
        for(i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
        }

        CLR(visited);
        cnt=0;
        int src;
        for(i=1;i<=l;i++){
            scanf("%d",&src);
            bfs(src);
        }

        printf("%d\n",cnt);
    }

    return 0;
}
