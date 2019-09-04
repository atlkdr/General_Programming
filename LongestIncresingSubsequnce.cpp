#include<iostream> 
#include <list> 
#include <stack> 
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int lis(int arr[],int n){
    int sum_arr[n];
    // ALL ARE lONGEST IN SUB OF SIZE 1
    for(int i=0;i<n;i++) sum_arr[i]=1;
    
    for(int i=1;i<n;i++){
        // Longest Ending here
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && sum_arr[j]+1>sum_arr[i]){
                sum_arr[i]=sum_arr[j]+1; // Condition check for cases liske  10 20 3 99
            }
        }
    }
    int m=INT_MIN;
    for(int i=0;i<n;i++){
        m=max(m,sum_arr[i]);
    }
    return m;
}


int main()
{ 
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Length of lis is %d\n", lis( arr, n ) ); 
    return 0; 
} 

