#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
// longest Increasing Subsequence
using namespace std;

int LICS(int arr[],int N){
    int count[N];
    for(int i=0;i<N;i++){
        count[i]=1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(count[j]+1>count[i]){
                    count[i]=count[j]+1;
                }
            }
        }
    }
    int max1=INT_MIN;
    for(int i=0;i<N;i++){
        max1=max(max1,count[i]);
    }
    return max1;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LICS(arr,n)<<endl;
    return 0;
}
