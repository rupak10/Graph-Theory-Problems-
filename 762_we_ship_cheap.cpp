#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<queue>

using namespace std;

map<string, int> visited;
map<string, string> parent;

int bfs(string from, string to, map<string, vector<string> > graph){

    queue<string> q;
    q.push(from);
    visited[from]=1;

    while(!q.empty()){
        string top=q.front();
        q.pop();
        if(top==to){
            return visited[top];
        }
        int n = graph[top].size();
        for(int i=0;i<n;i++){
            string v = graph[top][i];
            if(visited[v]==-1){ //not visited yet
                visited[v]=visited[top]+1;
                parent[v]=top;
                q.push(v);
            }
        }
    }

    return -1;
}

void printPath(string a, string b){
    if(a==b){
        return;
    }
    printPath(parent[a], b);
    cout<<parent[a]<<" "<<a<<endl;
}

int main(){

    int E;
    bool flag = false;
    string s1,s2,from,to;

    while(cin>>E){

        map<string, vector<string> > graph;

        for(int i=1;i<=E;i++){
            cin>>s1>>s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);

            visited[s1]=-1;
            visited[s2]=-1;
        }

        cin>>from>>to;
        if(flag){
            printf("\n");
        }
        flag = true;
        if(bfs(from,to,graph)!=-1){
            printPath(to, from);
        }
        else{
            printf("No route\n");
        }

    }

    return 0;
}
