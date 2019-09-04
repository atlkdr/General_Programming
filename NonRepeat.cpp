#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    // Hash Map
    string s="helo whorldew";
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]+=1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ' && mp[s[i]]==1){
            cout<<i<<" "<<s[i]<<endl;
            break;
        }
    }
    // Brute FORCE Do take care of comparision i=1 to n and j=1 to n also i!=j ( Else h -> no h hence non repeting first : False)
    bool condition=false;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' ') continue;
        condition=true;
        for(int j=0;j<s.size();j++){
            if( i!=j && s[j] == s[i]){
                condition=false;
                break;
            }
        }
        if(condition){
            cout<<i<<" "<<s[i]<<endl;
            break;
        }
    }
    // Index Array methord
    int index[26];
    // ALL SEEN FOR THE FIRST TIME
    memset(index,-1,sizeof(index));
    for(int i=0;i<s.size();i++){
        int c_ind = (int)(s[i]-'a');
        if(index[c_ind]==-1){
            // First TIME VISIT
            index[c_ind]=i;
        }else{
            index[c_ind]=-2;
        }
    }
    int min=INT_MAX,ind=-1;
    for(int i=0;i<26;i++){
        if(index[i]>=0 && index[i]<min){
            min=index[i];
            ind=i;
        }
    }
    if(ind!=-1){
        char c=(char)('a'+ind);
        cout<<min<<" "<<c<<endl;
    }
    return 0;
}
