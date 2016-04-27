#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
#include<string>
using namespace std;
#define N 30
#define CLR(a) memset(a, 0, sizeof(a))

vector<int> order[N];
int taken[N],indegree[N],weight[N],myArray[N];
int total_days,max_val;

int toNode(char ch) {
    return ch - 'A';
}

void topsort() {

    CLR(taken);
    int i,j;
    vector<int> task;
    CLR(myArray);

    total_days=0;
    for(i=0; i<27; i++) {

        max_val=0;
        for(int m=0; m<27; m++) {
            if(!indegree[m] && !myArray[m]) {
                myArray[m]=1;
                int day = weight[m];
                max_val = max(max_val,day);
            }
        }

        total_days +=max_val;

        for(j=0; j<27; j++) {

            if(!taken[j] && !indegree[j]) {
                //task.push_back(j);
                taken[j]=1;

                for(int k=0; k<order[j].size(); k++) {
                    --indegree[order[j][k]];
                }

                break;
            }
        }


    }

    cout<<max_val<<endl;



}

void clear_order() {
    for(int i=0; i<=N; i++) {
        order[i].clear();
    }
}

int main() {

    string str;
    char ch;
    int w,st,test;
    stringstream ss;

    cin>>test;

    //getline(cin,str);
    while(test--) {

        CLR(weight);
        clear_order();
        CLR(indegree);

        for(int i=1; i<=7; i++) {
            getline(cin,str);
            ss.clear();
            ss<<str;
            ss>>ch;
            //cout<<toNode(ch)<<endl;
            st=toNode(ch);
            ss>>w;
            weight[st]=w;
            //cout<<w<<endl;
            while(ss>>ch) {
                //cout<<toNode(ch)<<" ";
                int a = toNode(ch);
                order[st].push_back(toNode(a));
                ++indegree[a];
            }

        }

        topsort();
        cout<<endl;





    }



    return 0;
}
