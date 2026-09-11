#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void primesfactor(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
           int count=0;
           while(n%i==0){
            count++;
            n/=i;
           }
           cout<<i<<"^"<<count<<" ";
        }
    }
    if(n>1) cout<<n<<"^"<<"1";
    
}


int main(){
    int n;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    primesfactor(n);


    return 0;
}