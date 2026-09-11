#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int solve(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int maxclose=INT_MAX;
        int closeNo=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int close=abs(nums[mid]-target);
            if(close<=maxclose) {
                maxclose=close;
                closeNo=nums[mid];
            }
            else if(close == maxclose && nums[mid] < closeNo){
                // Smaller element on tie;
                closeNo = nums[mid];
            }

            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                low=mid+1;

            }
            else high=mid-1;
        }
        return closeNo;

    }

};


int main(){
    int n;
    cout<<"Enter Te Size Of Arrays::"<<endl;
    cin>>n;

    int target;
    cout<<"Enter Target Element"<<endl;
    cin>>target;
    vector<int>ans(n);
    cout<<"Enter Arrays Element::"<<endl;
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    solution obj;
    int ele=obj.solve(ans,target);
    cout<<ele;

    return 0;
}