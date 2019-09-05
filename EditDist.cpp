#include <iostream>
#include <string>

using namespace std;

void minDist(string a,string b){
    int dp[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else{
                if( a[i-1] == b[j-1] ){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
    }
    cout<<dp[a.size()][b.size()]<<endl;
}

int main()
{
    string str1 = "sunday"; 
    string str2 = "saturday"; 
    minDist(str1,str2);
    return 0;
}
