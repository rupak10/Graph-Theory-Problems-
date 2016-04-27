#include<iostream>
using namespace std;

int main(){

    long long int n,m,a,l,w,num;

    cin>>n>>m>>a;

    l = n%a;
    w = m%a;
    num = l*w;

    cout<<num<<endl;

    return 0;
}
