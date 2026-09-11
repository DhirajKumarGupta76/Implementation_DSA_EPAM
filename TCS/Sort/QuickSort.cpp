#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int partiation(vector<int>&nums,int low,int high){
        int pivot=nums[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(pivot>=nums[j]){
                i++;
                swap(nums[i],nums[j]);
            }

        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
    void quicksort(vector<int>&nums,int low,int high){
        if(low<high){
            int partiationindex=partiation(nums,low,high);
            quicksort(nums,low,partiationindex-1);
            quicksort(nums,partiationindex+1,high);

        }

    }

};

int main(){
    int n;
    cout<<"ENTER The LENGHT OF ARRAYS::"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"ENTER THE ELMENT OF ARRAYS::"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solution obj;

     obj.quicksort(arr,0,n-1);
    for(auto it:arr){
        cout<<it<<" ";
    }

    return 0;
}