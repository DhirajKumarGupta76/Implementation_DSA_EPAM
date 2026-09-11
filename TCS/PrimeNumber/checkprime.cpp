#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    
    //even factor
    if(n<2) return false;
   
   for(int i=2;i*i<=n;i++){
    if(n%i==0) return false;
   }
   return true;
}

int main(){
    int n;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    if(isprime(n)){
        cout<<"is prime"<<endl;

    }
    else{
        cout<<"Is not Prime"<<" ";
    }

    return 0;
}