#include<iostream> 
#include <list> 
#include <stack> 
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Recursion
int knapSack(int W,int wt[],int val[],int n){
    if(n==0 || W == 0) return 0;
    if(wt[n-1]>W) return knapSack(W,wt,val,n-1);
    return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
}
// Dynamic : Hint :: Answer dependent on immediate two values only
int knapSackDP(int W,int wt[],int val[],int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=W;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j) // Taking less than equal to Capacity 
            dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50;  // Max Capacity
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapSackDP(W, wt, val, n)); 
    return 0; 
} 

