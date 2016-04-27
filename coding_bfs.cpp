#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> G[100];
queue<int> Q;

void bfs(int N, int src, int dsNation)
{
    Q.push(src);
    int visited[100]= {0};
    int level[100];
    int parent[100];
    int path[100];

    visited[src]=1;
    level[src]=0;

    while(!Q.empty())
    {

        int u=Q.front();

        for(int i=0; i<G[u].size(); i++)
        {

            int v=G[u][i];

            if(!visited[v])
            {
                visited[v]=1;
                level[v]=level[u]+1;
                parent[v]=u;
                Q.push(v);
            }
        }
        Q.pop();
    }

    cout<<"Distance Between "<<src<<" and "<<dsNation<<" is: ";
    cout<<level[dsNation]<<endl;

    int k=-1;
    path[++k]=dsNation;

    while(path[k]!=src){
        path[++k]=parent[path[k-1]];
    }
    cout<<"Path From "<<src<<" to "<<dsNation<<" : ";
    for(int i=k;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<endl;

}

int main()
{

    int N,E;
    int x,y;
    int src,dsNation;

    cout<<"Enter Node and Edge Number : ";
    cin>>N>>E;

    for(int i=1; i<=E; i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    while(cin>>src>>dsNation){
        bfs(N, src, dsNation);
    }

    return 0;
}
