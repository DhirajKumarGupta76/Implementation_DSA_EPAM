#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int> solve(vector<int>& nums, int target) {
       unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        int need=target-nums[i];
        if(mpp.find(need)!=mpp.end()){
            return{mpp[need],i};

        }
        mpp[nums[i]]=i;

    } 
    return {-1,-1};
    }

};

int main(){
    solution obj;
    int n;
    cout<<"Enter The lrnght of arrays"<<endl;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the Target"<<endl;
    cin>>target;
    vector<int>ans=obj.solve(arr,target);

        cout << "Indices: ";

   
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout << endl;


    return 0;
}

