#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> &a){
    int n = 9;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    vector<vector<bool>> row(9,vector<bool>(10));
    vector<vector<bool>> col(9,vector<bool>(10));
    vector<vector<bool>> square(9,vector<bool>(10));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0)continue;
            if(row[i][a[i][j]]||col[j][a[i][j]]||square[(i/3)*3+j/3][a[i][j]]){
                // cout<<i<<" "<<j<<endl;
                // cout<<row[i][a[i][j]]<<col[j][a[i][j]]<<square[(i/3)*3+j/3][a[i][j]]<<endl;
                return false;
            }
            row[i][a[i][j]]=col[j][a[i][j]]=square[(i/3)*3+j/3][a[i][j]]=true;
        }
    }
    // cout<<"True"<<endl;
    return true;
}

bool solve(vector<vector<int>> &a, int index){
    int n = 9;
    if(index==81)return true;
    int r = index/9;
    int c = index%9;
    if(a[r][c]!=0) return solve(a,index+1);
    for(int i=1;i<=9;i++){
        a[r][c] = i;
        if(check(a)){
            if(solve(a,index+1)){
                return true;
            }
        }
    }
    a[r][c]=0;
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        vector<vector<int>> a(9,vector<int>(9));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>a[i][j];
            }
        }
        cout<<"Test case "<<q+1<<":\n";
        if(!solve(a,0)){
            cout<<"No solution possible."<<endl<<endl;
            continue;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}