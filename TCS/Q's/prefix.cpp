# include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    string solve(vector<string>&nums,int n){
        string prefix=nums[0];
        for(int i=1;i<n;i++){
            while(nums[i].find(prefix)!=0){
                prefix.pop_back();
            }
        }
        
        return prefix;
    }

};
int main(){
    int n;
    cin>>n;
    
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solution obj;
    string ans=obj.solve(arr,n);
    cout<<ans<<" ";



    return 0;
}