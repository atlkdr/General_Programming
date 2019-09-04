#include<iostream> 
#include <list> 
#include <stack> 
#include <list>
#include <algorithm>
#include <bits/stdc++.h>
// Longest Common Subsequence
using namespace std;

// Recursion
int lcs(char* a,char* b,int m,int n){
    if(m==0 || n==0) return 0;
    else{
        if(a[m] == b[n]) return 1+lcs(a,b,m-1,n-1);
        else{
            return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
        }
    }
} 
// DP NOTE COUNTING NULL SYMNOL ALSO
int LCSDP(string a,string b,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}


int main(){
    string X= "A";  
    string Y= "AGWGTABW";
    cout<<LCSDP(X,Y,sizeof(X),sizeof(Y))<<endl;
    return 0; 
} 

