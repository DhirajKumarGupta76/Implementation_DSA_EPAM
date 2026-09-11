# include<iostream>
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int fibo(int n){
        // 0 1 1 2 3 5 8 ......
        if(n<=1) return n;

        int sum=fibo(n-1)+fibo(n-2);
        return sum;
    
    }

};
int main(){
    int n;
    cin>>n;
    solution obj;
    int result=obj.fibo(n);
    cout<<result;

    return 0;
}