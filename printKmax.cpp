#include <bits/stdc++.h> 
#include <algorithm>

using namespace std; 


int maximum(int arr[],int start,int end){
    int maxi=INT_MIN;
    for(int i=start;i<end;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

int printKMax(int arr[],int n,int k){
    int maxi=INT_MIN;
    int temp;
    temp=maximum(arr,0,k);
    cout<<temp<<" ";
    if(temp>maxi) maxi=temp;
    for(int i=1;i<=n-k;i++){
        temp=maximum(arr,i,i+k);
        if(temp>maxi) maxi=temp;
        cout<<temp<<" ";
    }
    cout<<"\nMaximum:"<<maxi<<endl;
}


int main() 
{ 
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    printKMax(arr,n,k); 
    return 0; 
}
