#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"Enter The String"<<endl;
    getline(cin,s);
    int count1=0;  //*

    //  int count2=0;  //#

    for(int i=0;i<s.size();i++){
        if(s[i]=='*') count1++;
         else count1--;
    }
    // if(count1=count2) cout<<"0";
    // else if(count1>count2) cout<<"1";
    // else cout<<"-1";

    cout<<count1<<" ";


    
return 0;
    
}