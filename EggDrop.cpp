#include<iostream> 
#include <list> 
#include <stack> 
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Recursion
int eggDrop(int e,int k){
    if(k==0 || k == 1) return k;
    if(e==1) return k; // < 0 No change as dexrement always by 1 and check if n==1
    int mi=INT_MAX;
    // Drop At any floor and see the max min possible
    for(int i=1;i<=k;i++){
        // Gir ke tooth aur lower floors me search ya bach ja aur upar ke floors me search
        int cost=1+max(eggDrop(e-1,i-1),eggDrop(e,k-i));
        mi=min(mi,cost);
    }
    return mi;
} 

// Dynamic Programming
int eggDropDP(int e,int k){
    int dp[e+1][k+1];
    for(int i=1;i<=e;i++){
        dp[i][1]=1;
        dp[i][0]=0;
    }
    for(int j=1;j<=k;j++){
        dp[1][j]=j;
    }
    for(int i=2;i<=e;i++){
        for(int j=2;j<=k;j++){
            dp[i][j]=INT_MAX;
            for(int l=1;l<=j;l++){
                int chem=1+max(dp[i-1][l-1],dp[i][j-l]);
                cout<<chem<<endl;
                if(chem<dp[i][j]){
                    dp[i][j]=chem;
                    cout<<dp[i][j]<<endl;
                }
            }
        }
    }
    
    return dp[e][k];
}

int practice(int e,int k){
    int dp[e+1][k+1];
    for(int i=1;i<=e;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int j=1;j<=k;j++){
        dp[1][j]=j;
    }
    for(int i=2;i<=e;i++){
        for(int j=2;j<=k;j++){
            dp[i][j]=INT_MAX;
            for(int l=1;l<=j;l++){
                int res=1+max(dp[i-1][l-1],dp[i][j-l]);
                dp[i][j]=min(res,dp[i][j]);
            }
        }
    }
    return dp[e][k];
}

int main(){
    cout<<"MIN ATTEMPS:(WORST) "<<practice(2,36)<<endl;
    return 0; 
} 

