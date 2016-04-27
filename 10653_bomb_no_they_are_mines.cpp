#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>

#define mem(a, v) memset(a, v, sizeof(a))
using namespace std;

int R,C,r;
bool grid[1002][1002];
bool vis[1002][1002];
int cost[1002][1002];

int Dx[]={0, 0, 1, -1};
int Dy[]={1, -1, 0, 0};//Direction array

void bfs(int sx, int sy, int dx, int dy){

    int x,y;
    mem(vis, false);
    mem(cost, 0);

    queue<pair<int, int> > q;
    pair<int, int> pii;
    pii.first=sx;
    pii.second=sy;
    q.push(pii);

    vis[sx][sy]=true;
    cost[sx][sy]=0;

    while(!q.empty()){

        pii=q.front();
        q.pop();

        if(pii.first==dx && pii.second==dy){
            cout<<cost[dx][dy]<<endl;
            return;
        }

        for(int i=0;i<4;i++){
            x=pii.first+Dx[i];
            y=pii.second+Dy[i];
            if(x>=0&&x<=R-1&&y>=0&&y<=C-1&&!vis[x][y]&&!grid[x][y]){//check boundary
                vis[x][y]=true;
                cost[x][y]=cost[pii.first][pii.second]+1;
                q.push(make_pair(x,y));
            }
        }

    }


}


int main(){

    //Accepted
    int i,j;

    while(scanf("%d%d",&R,&C)==2){
        if(!R && !C){
            break;
        }
        mem(grid, false);
        scanf("%d",&r);

        int row,col,n;
        for(i=0;i<r;i++){
            cin>>row>>n;
            for(j=0;j<n;j++){
                cin>>col;
                grid[row][col]=true;
            }
        }

        int sx,sy,dx,dy;
        cin>>sx>>sy;
        cin>>dx>>dy;

        bfs(sx,sy,dx,dy);

    }

    return 0;
}
