#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int farm_collector(int milk[],int apple[],int N,int P){
    // Each Farm can have energy at max to go to the Nth Farm
    int dp[N+1][N+1];
    memset(dp,-1,sizeof(dp));
    dp[0][min(P,N)]=0; // Apples colleted is 0 here
    for(int i=1;i<=N;i++){
        // Energy levels possible
        for(int j=1;j<=N;j++){
            dp[i][j-1]=max(dp[i][j-1],dp[i-1][j]+apple[i-1]);
            dp[i][min(j-1+milk[i-1],N)]=max(dp[i][min(j-1+milk[i-1],N)],dp[i-1][j]);
        }
        dp[i][0]=max(dp[i][0],dp[i-1][0]); // Carry forward colleced appless to end
    }
    int max1=INT_MIN;
    for(int i=0;i<=N;i++){
        max1=max(max1,dp[N][i]);
    }
    return max1;
}

int main()
{
    int N=5,P=1;
    int arr[]={3,0,0,1,2};
    int arr2[]={4,5,1,10,20};
    cout<<farm_collector(arr2,arr,N,P)<<endl;
    return 0;
}
