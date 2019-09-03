#include <bits/stdc++.h>
using namespace std; 

// Destroy the possibilty of other elemnet being majority element and establishing self possibility
bool getMagority(int arr[],int N,int& el){
    int mel=arr[0];
    int mcount=1;
    for(int i=1;i<N;i++){
        if(arr[i] == mel){
            mcount+=1;
        }else{
            mcount-=1;
            if(mcount==0){
                mel=arr[i];
                mcount=1;
            }
        }
    }
    // Verify If Indeed it's Majority elemnet
    if(mcount>0){
        mcount=0;
        for(int i=0;i<N;i++){
            if(arr[i] == mel) mcount++;
        }
        el=mel;
        return (mcount>=((N/2)+1));
    }
    return false;
}

int main(){ 
    int arr[] = {1, 1, 2, 1, 3, 5, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int el;
    if(getMagority(arr,n,el)){
        cout<<"Majority EL: "<<el<<endl;   
    }
    return 0; 
} 
