#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
int solve(int n,int k,int j,int m,int p){

 int eaten1=m/k;
 int eaten2=p/j;
 if(m%k!=0 || p%j!=0){
    eaten1++;
 }
 return n-(eaten1+eaten2);

}
};

int main(){
    int n;
    cout<<"Enter Number of Monkey"<<endl;
    cin>>n;

    int k;
    cout<<"Enter Number of bananas eatable by a single monkey"<<endl;
    cin>>k;

    int j;
    cout<<"Enter Number of bananas eatable by a single monkey"<<endl;
    cin>>j;

    int m;
    cout<<"Enter Total Number of Bananas"<<endl;
    cin>>m;

    int p;
    cout<<"Enter Total Number of Peanauts"<<endl;
    cin>>p;

    solution obj;
    cout<<obj.solve(n,k,j,m,p);


    return 0;
}