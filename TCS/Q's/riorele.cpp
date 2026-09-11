#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int solve(vector<int>&nums ,int n){
        int count=1;
    int prior=nums[0];
    for(int i=1;i<n;i++){
        if(prior<nums[i]){
            count++;
        prior=nums[i];

        } 
    }
    return count;

    }
    
};

int main(){
    int n;
    cout<<"Enter the size of arrays "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the element of arrays "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int count=1;
    // int prior=arr[0];
    // for(int i=1;i<n;i++){
    //     if(prior<arr[i]){
    //         count++;
    //     prior=arr[i];

    //     } 

    // }
    // cout<<count<<" ";

    solution obj;

    cout<<obj.solve(arr,n)<<" ";


    return 0;

}