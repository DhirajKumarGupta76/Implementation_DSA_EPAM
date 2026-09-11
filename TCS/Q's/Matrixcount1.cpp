# include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    int row=-1;
    int maxcount=0;
     for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                count++;
            }
        }
        if(maxcount<count){
            row=i;
            count=maxcount;
        }

    }
    if(row==-1) cout<<"-1";
    else cout<<row+1;

    return 0;
}