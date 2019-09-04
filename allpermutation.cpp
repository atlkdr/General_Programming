#include<iostream> 
#include <list> 
#include <stack> 
#include <list>
#include <algorithm>

using namespace std;

void printAll(string s,int index){
    if(index==s.size()){
        cout<<s<<endl;
        return;
    }
    sort(s.begin()+index,s.end());
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        printAll(s,index+1);
        swap(s[index],s[i]);
    }
    return;
}

int main(){
    printAll("EDACB",0);
    return 0;
}

