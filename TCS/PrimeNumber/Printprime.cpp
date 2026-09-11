#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    void solve(int n){
        while(n%2==0){
            cout<<"2"<<" ";
            n/=2;
        }
        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                cout<<i<<" ";
                n/=i;
            }
        }
        if(n>1) cout<<n;
    }

};

int main(){
    int n;
    cout<<"Enter The Number"<<endl;

    cin>>n;
     solution obj;
     obj.solve(n);
    

    return 0;
}