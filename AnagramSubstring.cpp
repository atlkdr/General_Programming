#include<iostream> 
#include<cstring> 
#include <string>
#include <map>
#define MAX 256 
using namespace std;

bool check(map<char,int> mp,map<char,int> x){
    for(auto it=mp.begin();it!=mp.end();it++){
        char c=it->first;
        int val=it->second;
        if(x[c]!=val) return false;
    }
    return true;
}
void search(string a,string b){
    map<char,int> pat,text;
    for(int i=0;i<b.size();i++){
        pat[b[i]]+=1;
    }
    for(int i=0;i<b.size();i++){
        text[a[i]]+=1;
    }
    int i=0;
    int j=b.size()-1;
    while(j<(a.size())){
        if(check(pat,text)){
            cout<<a.substr(i,1+j-i)<<endl;
            return;
        }
        j++;
        text[a[j]]+=1;
        text[a[i]]-=1;
        i++;
    }
    cout<<"NONE"<<endl;
}


int main() 
{ 
    string a = "XACDGAXBCDA"; 
    string b = "ABCD"; 
    search(a,b); 
    return 0; 
}
