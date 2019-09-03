#include <iostream> 
#include <vector>
using namespace std;


int peakElemnet(int arr[],int start,int end){
    if(start == end) return arr[start];
    int mid=start+((end-start)/2);
    if(mid>start && mid<end){
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }
    }
    if(mid>start && arr[mid]<arr[mid-1]){
        return peakElemnet(arr,start,mid-1);
    }else if(mid<end && arr[mid]<arr[mid+1])
        return peakElemnet(arr,mid+1,end);
} 


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<peakElemnet(arr,0,n-1)<<endl;
    return 0;
}
