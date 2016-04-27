#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    //Accepted
    int from,to,total_node,legal_node,E,ttl,result,testCase=0;
    map<int, vector<int> > graph;
    map<int, int> dist;
    while(cin>>E)
    {
        if(E==0)
        {
            break;
        }
        graph.clear();
        for(int i=1; i<=E; i++)
        {
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        total_node = graph.size();
        while(cin>>from>>ttl)
        {
            if(from==0 && ttl==0)
            {
                break;
            }
            dist.clear();

            queue<int> q;
            q.push(from);
            dist[from]=0;
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
                        q.push(v);
                    }
                }
            }
            legal_node=0;
            for(map<int, int>::iterator it=dist.begin(); it!=dist.end(); it++)
            {
                if(it->second <= ttl)
                {
                    legal_node++;
                }
            }

            result = total_node-legal_node;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++testCase, result, from, ttl);
        }
    }

    return 0;
}
