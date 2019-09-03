#include <bits/stdc++.h>
#include <stack>
#include <map>
#define COL 4
#define ROW 5
using namespace std; 
  
void printMatrix(int M[ROW][COL]){
    for(int k=0;k<ROW;k++){
        int i=k;
        int j=0;
        while((i>=0) && (j<COL)){
            cout<<M[i][j]<<" ";
            i--;
            j++;
        }cout<<"\n";
    }
    for(int k=1;k<COL;k++){
        int i=ROW-1;
        int j=k;
        while((i>=0) && (j<COL)){
            cout<<M[i][j]<<" ";
            i--;
            j++;
        }cout<<"\n";
    }
}

int main(){ 
    int M[ROW][COL] = {{1, 2, 3, 4}, 
                       {5, 6, 7, 8}, 
                       {9, 10, 11, 12}, 
                       {13, 14, 15, 16}, 
                       {17, 18, 19, 20}};
    printMatrix(M);
    return 0; 
} 
