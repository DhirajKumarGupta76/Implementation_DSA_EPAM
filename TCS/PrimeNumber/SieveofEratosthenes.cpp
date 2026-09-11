//print all prime 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number"<<endl;
    cin>>n;
    vector<int>ans(n+1,true);
    ans[0]=false;
    ans[1]=false;
    for(int i=2;i*i<=n;i++){
        if(ans[i]){
            for(int j=2*i;j<=n;j+=i){
                ans[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(ans[i]==true){
            cout<<i<<" ";
        }
    }

    return 0;

}

