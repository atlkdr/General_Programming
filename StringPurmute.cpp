#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

string convert(char* x,int s){
    string temp="";
    for(int i=0;i<s;i++){
        temp+=x[i];
    }
    return temp;
}

void purmute(char c[],int index,vector<string>& final,int s){
    if(index==s){
        string temp=convert(c,index);
        cout<<temp<<endl;
        final.push_back(temp);
        return;
    }
    for(int i=index;i<s;i++){
        char temp=c[index];
        c[index]=c[i];
        c[i]=temp;
        purmute(c,index+1,final,s);
        temp=c[index];
        c[index]=c[i];
        c[i]=temp;
    }
}


int main(){
    string x="car";
    if(x.find("ca")!=string::npos){
        cout<<"FOUND"<<endl;
    }
    vector<string> vec;
    char c[]={'c','a','r','\0'};
    purmute(c,0,vec,3);
    
    return 0; 
} 
