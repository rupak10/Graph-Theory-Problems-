#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

#define loop(i, n) for(int i=0;i<n;i++)
#define mem(a, v) memset(a, v, sizeof(a))
using namespace std;

string graph[8];
bool visited[8][8];
char possible[]="IEHOVA#";
int level,len,n;
vector<int> direction;

bool check(char c){
    loop(i, 7){
        if(possible[i]==c){
            return true;
        }
    }
    return false;
}

void dfs(int l, int pos){

    if(pos+1<len){
        if(!visited[l][pos+1] && check(graph[l][pos+1])){
            visited[l][pos+1]=true;
            //2 for right
            direction.push_back(2);
            if(graph[l][pos+1]!='#'){
                dfs(l, pos+1);
            }
            else{
                return;
            }

        }
    }

    if(pos-1>=0){
        if(!visited[l][pos-1] && check(graph[l][pos-1])){
            visited[l][pos-1]=true;
            //4 for left
            direction.push_back(4);
            if(graph[l][pos-1]!='#'){
                dfs(l, pos-1);
            }
            else{
                return;
            }
        }
    }

    if(l-1>=0){
        if(!visited[l-1][pos] && check(graph[l-1][pos])){
            visited[l-1][pos]=true;
            //6 for forth
            direction.push_back(6);
            if(graph[l-1][pos]!='#'){
                dfs(l-1, pos);
            }
            else{
                return;
            }
        }
    }

}

void printSpace(int i){
    if(i!=(n-1)){
        printf(" ");
    }
}


int main(){

    //Accepted
    int cases,pos;
    scanf("%d",&cases);

    while(cases--){
        scanf("%d%d",&level,&len);

        for(int i=0;i<level;i++){
            cin>>graph[i];
        }

        mem(visited, false);

        loop(i, len){
            if(graph[level-1][i]=='@'){
                pos=i;
                break;
            }
        }

        direction.clear();
        int l=level-1;
        dfs(l, pos);

        n = direction.size();
        for(int i=0;i<n;i++){
            if(direction[i]==2){
                printf("right");
                printSpace(i);
            }
            else if(direction[i]==4){
                printf("left");
                printSpace(i);
            }
            else{
                printf("forth");
                printSpace(i);
            }
        }

        printf("\n");

    }

    return 0;
}
