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


int main(){
    string s1="good boy";
    string s2="baod boy";
    int memo[20][20];
    memset(memo,0,sizeof(memo));
    cout<<LCS(s1,s2,0,0,memo)<<endl;
}
