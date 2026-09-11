# include<iostream>
# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    //imp line;
    cin.ignore();
    string s;
    cout<<"Enter string line"<<endl;
    getline(cin,s);
    cout<<n<<" "<<s<<" ";



    return 0;
}