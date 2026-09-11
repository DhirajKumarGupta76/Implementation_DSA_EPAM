#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    string solve(string s){
        int hr=stoi(s.substr(0,2));
        int mn=stoi(s.substr(3,2));
        int sec=stoi(s.substr(6,2));
        string time = s.substr(8,2);

       if(time=="PM" && hr != 12)
    hr += 12;
    if(time=="AM" && hr == 12)
    hr = 0;

    stringstream ss;

        ss << setw(2) << setfill('0') << hr << ":"
           << setw(2) << setfill('0') << mn << ":"
           << setw(2) << setfill('0') << sec;

        return ss.str();
        

    }

};
int main(){
    string s;
    cin>>s;
    solution obj;
    cout<<obj.solve(s);

    return 0;
}