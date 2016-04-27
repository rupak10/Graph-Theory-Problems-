#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define CLR(a) memset(a, 0, sizeof(a))
int n;
vector<int> graph[105];
int visited[105];

void clear_graph(){
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
}

void dfs(int src){

    int n = graph[src].size();

    for(int i=0;i<n;i++){
        int v = graph[src][i];
        if(!visited[v]){
            visited[v]=1;
            dfs(v);
        }
    }

    return;
}

void printValue(){

    vector<int> nodes;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            nodes.push_back(i);
        }
    }

    int len = nodes.size();
    printf("%d",len);
    for(int i=0;i<len;i++){
        printf(" %d",nodes[i]);
    }

    printf("\n");
}


int main(){

    int u,v,q,i;

    while(scanf("%d",&n)&&n){

        clear_graph();

        while(1){
            scanf("%d",&u);
            if(!u){
                break;
            }
            while(scanf("%d",&v)&&v){
                graph[u].push_back(v);
            }
        }

        scanf("%d",&q);
        int src;
        for(i=1;i<=q;i++){
            scanf("%d",&src);
            CLR(visited);
            dfs(src);
            printValue();
        }
    }

    return 0;
}
