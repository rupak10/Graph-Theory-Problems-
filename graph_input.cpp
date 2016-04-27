#include<iostream>
#include<cstdio>

using namespace std;

int main(){

  int matrix[10][10];
  int node,n1,n2;

  cout << "Enter The Node Number : ";
  cin >> node;

  for(int i = 1; i <= node; i++){

    for(int j = 1; j <= node; j++){

        cin >> matrix[i][j];
    }
  }

  cout << endl;

  while(cin >> n1 >> n2){

     if(matrix[n1][n2] != 0){
       cout << "Connection Exists Between " << n1 << " And " << n2 << endl;
    }
     else{
       cout << "No Connection Between " << n1 << " And " << n2 << endl;
    }

  }
  //cout << "enter node 1 : ";
  //cin >> n1;
  //cout << "enter node 2 : ";
  //cin >> n2;


  /*
  for(int i = 1; i <= node; i++){

    for(int j = 1; j<= node; j++){

        cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  */

  //cout << "\n\nInput Complete!!!\n\n";



  return 0;
}
