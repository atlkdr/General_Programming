#include <iostream>
using namespace std;

void maxsumSub(int arr[],int n,int k){
    int max_sum=0;
    int max_sum_ind=0;
    for(int i=0;i<k;i++){
        max_sum+=arr[i];
    }
    int sum=max_sum;
    int lower_bound=0;
    for(int i=k;i<n;i++){
        sum=sum+(arr[i]-arr[i-k]);
        if(sum>max_sum){
            max_sum=sum;
            max_sum_ind=i-k+1;
        }
    }
    cout<<max_sum/k<<" "<<max_sum_ind<<endl;
}


int main()
{
    int arr[]={11,-8,16,-7,24,-2,3}; 
    maxsumSub(arr,sizeof(arr)/sizeof(arr[0]),3);
        

    return 0;
}
