#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

#define CLR(a) memset(a, 0, sizeof(a))
int n,order[110][110],taken[110],indegree[110];

void topsort(){
    CLR(taken);
    vector<int> task;
    int i,j;
    for(i=1;i<=n;i++){

        for(j=1;j<=n;j++){

            if(!taken[j] && !indegree[j]){
                task.push_back(j);
                taken[j]=1;

                for(int k=1;k<=n;k++){
                    if(order[j][k]){
                        --indegree[k];
                    }
                }

                break;
            }
        }
    }

    int l=task.size();
    for(i=0;i<l;i++){
        cout<<task[i];
        if(i!=(l-1)){
            cout<<" ";
        }
    }
    task.clear();
    cout<<endl;
}

int main(){

    //Accepted
    int m,i,a,b;
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }

        CLR(order);
        CLR(indegree);

        for(i=1;i<=m;i++){
            cin>>a>>b;
            order[a][b]=1;
            ++indegree[b];
        }

        topsort();
    }

    return 0;
}
