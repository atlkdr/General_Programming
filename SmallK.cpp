// smallest range containing elements from k lists
#include <bits/stdc++.h> 
#include <iostream>
# define N 5
#include <algorithm>
using namespace std; 

void minRange(int arr[][N],int row){
    int col_track[row];
    for(int i=0;i<row;i++) col_track[i]=0;
    // Looping till one of the next value become N i.e we can't take anymore
    int range=INT_MAX;
    int i,j;
    while(true){
        int min=INT_MAX;
        int max=INT_MIN;
        int min_ind;
        for(int i=0;i<row;i++){
            if(arr[i][col_track[i]]>max){
                max=arr[i][col_track[i]];
            }
            if(arr[i][col_track[i]]<min){
                min=arr[i][col_track[i]];
                min_ind=i; // Kis Row me minimum hai  ? 
            }
        }
        col_track[min_ind]++;
        if(col_track[min_ind] == N) break;
        if( (max-min) < range ){
            range = (max-min);
            i=min;
            j=max;
        }
    }
    cout<<"["<<i<<" , "<<j<<"]"<<endl; 
}


int main() 
{ 
    int arr[][N] = { 
                    {4, 7, 9, 12, 15}, 
                    {0, 8, 10, 14, 20}, 
                    {6, 12, 16, 30, 50} 
                    }; 
  
    int k = sizeof(arr)/sizeof(arr[0]); // Number of Rows Here
    minRange(arr,k); 
    return 0; 
} 
