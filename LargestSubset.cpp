#include <bits/stdc++.h>
#include <set>
using namespace std; 
// Largest Subset with consecutive numbers

int main(){
    set<int> max_set;
    int arr[]={1,3,8,14,4,10,2,11,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    set<int> hash;
    for(int i=0;i<n;i++){
        hash.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        int start=arr[i];
        if(hash.find(start-1)==hash.end()){
            set<int> my;
            my.insert(start);
            while(hash.find(start+1)!=hash.end()){
                my.insert(start+1);
                start+=1;
            }
            if(my.size()>max_set.size()){
                max_set=my;
            }
        }
    }
    for(auto it=max_set.begin();it!=max_set.end();it++){
        cout<<*it<<" ";
    }cout<<"\n";
    return 0;  
}  
