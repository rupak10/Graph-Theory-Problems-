#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int main()
{

    int edge,source,destination;
    char s1[4],s2[4];
    map<string, int> mp;
    map<int, vector<int> > graph;
    map<int, int> dist;
    map<int, int> parent;

    while(cin>>edge)
    {

        mp.clear();
        graph.clear();
        dist.clear();
        parent.clear();

        int value = 0;
        for(int i=1; i<=edge; i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
            {
                mp[s1] = ++value;
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2] = ++value;
            }
            int from = mp[s1];
            int to = mp[s2];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        cin>>s1>>s2;
        source = mp[s1];
        destination = mp[s2];
        //cout<<source<<" "<<destination<<endl;
        //start of bfs
        queue<int> q;
        q.push(source);
        dist[source]=0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0; i<graph[u].size(); i++)
            {
                int v = graph[u][i];
                if(!dist.count(v))
                {
                    dist[v]=dist[u]+1;
                    parent[v]=u;
                    q.push(v);
                }
            }
        }
        //end of bfs

        //finding path
        vector<int> path;
        bool noRoute = false;
        path.push_back(destination);

        while(parent[destination]!=source){
            if(parent.find(parent[destination])==parent.end()){
                noRoute = true;
                break;
            }
            destination=parent[destination];
            path.push_back(destination);
        }
        if(parent[destination]==source){
            path.push_back(source);
        }

        if(noRoute){
            cout<<"No route"<<endl;
        }
        else{
            int vecSize = path.size();
            for(int i=vecSize-1;i>0;i--){

                cout<<path[i]<<" "<<path[i-1]<<endl;
            }
        }



    }

    return 0;
}
