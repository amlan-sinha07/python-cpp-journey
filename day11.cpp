#include <iostream>
#include <vector>
#include <random>
using namespace std;
int linear_search(vector<int>arr,int target){
    for (int i=0;i<arr.size();++i){
        if (arr[i]==target) return i;
    }
    return -1;
}
int binary_search(vector<int>arr,int target){
    int left=0;
    int right=arr.size()-1;
    while (left<=right){
        int mid=(left+right)/2;
        if (arr[mid]==target) return mid;
        else if (arr[mid]>target) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
void bubble_sort(vector<int>&arr){
    int n=arr.size();
    for (int i=0;i<arr.size();++i){
        for (int j=0;j<n-i-1;++j){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    vector<int>arr={64,25,12,22,11};
    
    cout<<linear_search(arr,22)<<endl;
    cout<<binary_search({11,12,22,25,64},25)<<endl;

    bubble_sort(arr);
    for (int x:arr) cout<<x<<" ";
    cout<<endl;

    return 0;
}