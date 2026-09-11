#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    stringstream ss(input);
    vector<int>nums;
    string token;
    while(getline(ss,token,' ')){
        int num=stoi(token);
        nums.push_back(num);
    }
    for(auto it:nums){
        cout<<it<<" ";
    }

    return 0;
}