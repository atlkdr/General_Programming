#include <iostream> 
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;




// Order ( n^2 ) TAKING EACH AS Center Excess Point: Expansion aroun every ceter
int palinDrone(string s){
    string modified="#";
    for(int i=0;i<s.size();i++){
        modified+=s[i];
        modified+='#'; // Add One Chaarcter At A time
    }
    int max_count=INT_MIN;
    for(int i=0;i<modified.size();i++){
        int j=i-1;
        int k=i+1;
        int count=0;
        if(modified[i]!='#') count+=1;
        while(j>=0 && k <modified.size()){
            if(modified[j] == modified[k]){
                if(modified[j]!='#')
                count+=2;
            }else{
                break;
            }
            j--;
            k++;
        }
        max_count=max(count,max_count);
    }
    return max_count;
}


int main(){
    string s="caarXac";
    cout<<palinDrone(s)<<endl;
    return 0;
}
