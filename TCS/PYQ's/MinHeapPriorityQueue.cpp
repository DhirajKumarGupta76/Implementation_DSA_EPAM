#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int solve(vector<int>&nums,int k){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:nums){
            if(pq.size()<k){
                pq.push(it);
            }
            else{
                if(pq.top()<it)
                pq.pop();
                pq.push(it);
            }
        }
        return pq.top();

    }
};
int main(){
    int k;
    cout<<"Kth Larget sell Product"<<endl;
    cin>>k;

    int n;
    cout<<"Enter The size of Arrays::"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solution obj;
    cout<<obj.solve(arr,k);

    return 0;
}