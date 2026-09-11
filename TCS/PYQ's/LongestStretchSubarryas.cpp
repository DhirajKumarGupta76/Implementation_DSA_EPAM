#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int k,int n){
   int low=0;
   int count=k;
   int maxlen=0;
   for(int high=0;high<n;high++){
    if(nums[high]==0){
        count--;
    }
    while(count<0){
        if(nums[low]==0){
            count++;
        }
        low++;
    }
    maxlen=max(maxlen,high-low+1);
   }
   return maxlen;
}

int main(){
    int N;
     cout<<"ENTER THE LENGHT OF SUBARRAYS"<<endl;
    cin>>N;
    int K;
    cin>>K;
   
    vector<int>arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
   int ans= solve(arr,K,N);
   cout<<"The Answer Is::"<<endl;
   cout<<ans<<endl;


    return 0;
}

