#include<bits/stdc++.h> 
#include<string>

using namespace std; 

int LCS(string s1,string s2,int i,int j,int memo[20][20]){
    if(i==s1.size() || j==s2.size()) return 0;
    else{
        if(s1[i] == s2[j]){
            if(memo[i+1][j+1]==0)
                memo[i+1][j+1]=LCS(s1,s2,i+1,j+1,memo);
            return 1+memo[i+1][j+1];
        }else{
            if(memo[i+1][j] == 0)
            memo[i+1][j]=LCS(s1,s2,i+1,j,memo);
            if(memo[i][j+1] == 0)
            memo[i][j+1]=LCS(s1,s2,i,j+1,memo);
            return max(memo[i+1][j],memo[i][j+1]);
        }
    }
}
// Diagonal One is clear but when no match happens at index i max from left ( Denoting max matched till now ) and from up ( Denoting max match till now withous considering the element  ) must be taken into account
int LCSDP(string s1,string s2){
    int dp[s1.size()+1][s2.size()+1];
    for(int i=0;i<=s1.size();i++) dp[i][0]=0;
    for(int j=0;j<=s2.size();j++) dp[0][j]=0;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i] == s2[j])
            dp[i][j]=1+dp[i-1][j-1];
            else{
                // Carry forward For others
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}


int main(){
    string s1="AGGTAB";
    string s2="GXTXAYB";
    int memo[20][20];
    memset(memo,0,sizeof(memo));
    cout<<LCS(s1,s2,0,0,memo)<<endl;
    cout<<LCSDP(s1,s2)<<endl;
}
