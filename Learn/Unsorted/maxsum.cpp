#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int q=0;q<t;q++){
        int n;
        cin >> n;
        int ma = INT_MIN;
        vector<vector<int>> a(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
                ma = max(ma,a[i][j]);
            }
        }
        vector<vector<int>> pre(n,vector<int>(n+1));
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                pre[i][j] = pre[i][j-1]+a[i][j-1];
                // cout << pre[i][j] << " ";
            }
            // cout << endl;
        }
        jasdf;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=0;k<n;k++){
                    sum+=pre[k][j+1]-pre[k][i];
                    // cout << sum << " " << pre[k][j+1]-pre[k][i] << endl;
                    ma = max(ma,sum);
                    if(sum<0){
                        sum = 0;
                    }
                }
            }
        }
        cout << ma << endl;
    }
}