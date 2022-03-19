#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        // k++;
        vector<vector<char>> a(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        // cout<<"CHECK"<<endl;
        vector<vector<vector<int>>> right(k+1,vector<vector<int>>(n,vector<int>(n)));
        vector<vector<vector<int>>> down(k+1,vector<vector<int>>(n,vector<int>(n)));
        for(int i=0;i<n;i++){
            right[0][i][0]=1;
            right[0][0][i]=1;
            down[0][0][i]=1;
            down[0][i][0]=1;
        }
        int result=0;
        for(int turn=1;turn<=k;turn++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][j]=='H')continue;
                    // right[turn][i][j]=right[turn-1][i][j];
                    if(i!=0)right[turn][i][j]+=right[turn][i-1][j];
                    if(j!=0)right[turn][i][j]+=down[turn-1][i][j-1];
                    cout<<right[turn][i][j]<<" ";
                }
                cout<<endl;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][j]=='H')continue;
                    // down[turn][i][j]=down[turn-1][i][j];
                    if(i!=0)down[turn][i][j]+=right[turn-1][i-1][j];
                    if(j!=0)down[turn][i][j]+=down[turn][i][j-1];
                }
            }
            result+=right[turn][n-1][n-1]+down[turn][n-1][n-1];
        }
        // cout<<right[k][n-1][n-1]+down[k][n-1][n-1]<<endl;
        cout<<result<<endl;
    }
}