#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

#define CLR(a) memset(a, 0, sizeof(a))

string s1,s2;
bool vis[10][10];
int cost[10][10];
int Dx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int Dy[]= {-1,-2,-2,-1, 1,2, 2, 1};//direction array


void bfs(int sx, int sy, int dx, int dy){

    int x,y;
    CLR(vis);
    CLR(cost);

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
            cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<cost[dx][dy];
            cout<<" knight moves."<<endl;
            return;
        }

        for(int i=0;i<8;i++){
            x=pii.first+Dx[i];
            y=pii.second+Dy[i];
            if(x>=1&&x<=8&&y>=1&&y<=8&&!vis[x][y]){//check boundary
                vis[x][y]=true;
                cost[x][y]=cost[pii.first][pii.second]+1;
                q.push(make_pair(x,y));
            }
        }

    }

}


int main(){

    int sx,sy,dx,dy;

    while(cin>>s1>>s2){
        sx=s1[0]-96;
        sy=s1[1]-'0';

        dx=s2[0]-96;
        dy=s2[1]-'0';

        bfs(sx,sy,dx,dy);
    }

    return 0;
}
