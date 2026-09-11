#include <bits/stdc++.h>
using namespace std;
 // also can be done by mapping:;
class solution{
    public:
    char solve(string s){
        char ans;
        for(int i=0;i<s.size();i++){
           ans= ans^s[i];
        }
        return ans;

    
    

    }
    
};

int main(){
    string s;
    cout<<"Enter the size of string "<<endl;
    cin>>s;
    

    solution obj;

    cout<<obj.solve(s)<<" ";


    return 0;

}