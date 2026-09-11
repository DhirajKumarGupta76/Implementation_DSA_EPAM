#include <iostream>
# include <bits/stdc++.h>
using namespace std;
class solution{
    public:
   int  maxdigitrange(vector<int>& nums,int n){
    vector<int>range(n);
    int maxdigitrange=0;
    for(int i=0;i<n;i++){
        string temp=to_string(nums[i]);
       int mx=*max_element(temp.begin(),temp.end());
       int mn=*min_element(temp.begin(),temp.end());
       range[i]=mx-mn;
       maxdigitrange=max(range[i],maxdigitrange);

    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(range[i]==maxdigitrange){
            sum+=nums[i];
        }
        
    }
    return sum;

        
    }
};

 int main(){
    // solution obj;
    // int n;
    // cout<<"ENTER THE LENGHT OF ARRAYS"<<endl;
    // cin>>n;
    // vector<int>arr(n);
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // int ans=obj.maxdigitrange(arr,n);

    // cout<<"Max Digit Range"<<" "<<ans<<endl;

    solution obj;
    int t;
    cout<<"ENETR THE NUMBER OF INPUT"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"ENTER THE NUMBER ARRAYS'LENGHT"<<endl;
        cin>>n;
        vector<int>arr(n);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        } 
        int ans=obj.maxdigitrange(arr,n);
        cout<<"MAXDIGITRANGE=="<<" "<<ans<<endl;
    }


    return 0;

}

