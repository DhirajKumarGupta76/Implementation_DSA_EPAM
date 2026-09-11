#include<iostream>
using namespace std;
int main(){
    int A;
    cout<<"Enter the price of first item"<<endl;
    cin>>A;

    int B;
    cout<<"Enter the price of Second  item"<<endl;
    cin>>B;

    if(A<0 || B<0) cout<<"INVALID INPUT";
    else if(A==B)  cout<<"Equal Price";
     else if(A>B){
        cout<<A<<" is more expansive";
     }
     else  cout<<B<<" is more expansive";


    return 0;
}