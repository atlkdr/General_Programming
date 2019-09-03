#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
// Most Occuring Item in O(n) time and O(1) space
using namespace std;

int find_most(int arr[],int N,int k){
    for(int i=0;i<N;i++){
        arr[arr[i]%k]+=k;
    }
    int maxi=INT_MIN;
    for(int i=0;i<N;i++){
        maxi=max(arr[i],maxi);
        arr[i]=arr[i]%k;
    }
    return maxi%k;
}

int main()
{
    int arr[]={1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int k=10;
    cout<<find_most(arr,sizeof(arr)/sizeof(arr[0]),k)<<endl;
    return 0;
}
