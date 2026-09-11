#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int solve(vector<int>&nums,int n){
        stack<int>st;
        vector<int>pse(n,-1);
        vector<int>nse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&& nums[i]<nums[st.top()]){
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else(pse[i]=st.top());

            st.push(i);
        }
        //clear stck;
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& nums[i]<nums[st.top()]){
                st.pop();
            }
            if(st.empty()) nse[i]=n;
            else(nse[i]=st.top());

            st.push(i);
        }
       

        int maxarea=0;
         for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            int ht=nums[i];
            int area=ht*width;
            maxarea=max(maxarea,area);
        
        }


        return maxarea;
    }

};
int main(){
    int n;
    cout<<"Enter The lenght of arrays::"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the element of arrays "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solution obj;
    cout<<obj.solve(arr,n);


    return 0;
}