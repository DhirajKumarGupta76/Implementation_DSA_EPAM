#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int> solve(vector<int>&nums,int n){
        int low=0;int high=n-1;
        int mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        return nums;
        

    }

};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    solution obj;
    
    vector<int>ans=obj.solve(arr,n);
    for(auto it:ans){
        cout<<it<<" ";
    }


return 0;

}