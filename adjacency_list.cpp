#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define MAX 100000

using namespace std;

vector<int>edges[MAX];
map<int, int>in;
map<int, int>out;

int main(){

  int N,E;
  int i,j;
  printf("enter node and edges :");
  scanf("%d %d",&N,&E);

  for(i = 1; i <= E; i++){
    int x,y;
    scanf("%d %d",&x,&y);
    edges[x].push_back(y);
  }

  printf("\n\n");

    for(j = 1; j <= N; j++){
        printf("%d : ",j);
        for(i = 0; i < edges[j].size(); i++){
            in[edges[j][i]]++;
            printf("%d ",edges[j][i]);
        }
        printf("\n");
        out[j] = edges[j].size();
    }

  printf("\n\nNow The Program will print \n indegree and outdegree\n\n");

  for(int j = 1; j <= N; j++){
    printf("node : %d -> IN : %d  OUT : %d\n\n",j,in[j],out[j]);
  }
  return 0;
}
