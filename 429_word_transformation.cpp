#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

map<string, int> visited;

int bfs(string start, string to, map<string, vector<string> > graph){

    queue<string> q;
    q.push(start);
    visited[start]=0;

    while(!q.empty()){
        string top=q.front();
        q.pop();

        if(top==to){
            return visited[top];
        }

        int total=graph[top].size();

        for(int i=0;i<total;i++){
            if(!visited.count(graph[top][i])){
                visited[graph[top][i]]=visited[top]+1;
                q.push(graph[top][i]);
            }
        }
    }

}


int main(){

    //Accepted
    int n,i;
    scanf("%d",&n);
    string word,tmp;

    while(n--){

        int diff;
        map<string, vector<string> > graph;
        cin>>word;

        while(word!="*"){
            graph[word];
            map<string, vector<string> >:: const_iterator it;

            for(it=graph.begin();it!=graph.end();it++){

                tmp = (*it).first;
                int tmpL = tmp.size();
                diff=0;

                if(tmpL==word.size()){
                    for(i=0;i<tmpL&&diff<2;i++){
                        if(tmp[i]!=word[i]){
                            ++diff;
                        }
                    }
                }

                if(diff==1){
                    graph[word].push_back(tmp);
                    graph[tmp].push_back(word);
                }

            }

            cin>>word;
        }

        string line,start,to;

        getline(cin,line);
        while(getline(cin,line)){
            if(line==""){
                break;
            }
            int pos=line.find(" ");
            start=line.substr(0,pos);
            to=line.substr(pos+1,line.size());
            visited.clear();
            cout<<start<<" "<<to<<" "<<bfs(start,to,graph)<<endl;
        }

        if(n!=0){
            printf("\n");
        }


    }

    return 0;
}
