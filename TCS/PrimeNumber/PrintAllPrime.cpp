#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void primesfactor(int n){
    
    //even factor
   
     while (n%2==0){
        
        cout<<"2"<<" ";
        n/=2;
    

   }
    // odd factor;
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>1) cout<<n;
      
}


int main(){
    int n;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    primesfactor(n);


    return 0;
}