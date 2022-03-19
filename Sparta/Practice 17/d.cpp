#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //if odd remove all evens
    if(k%2!=0){
        vector<int> newa;
        for(int i:a){
            if(i%2!=0){
                newa.push_back(i);
            }
        }
        a = newa;
        n = newa.size();
    }

    //if not 5 or 0, remove all 5
    if(k%5!=0){
        vector<int> newa;
        for(int i:a){
            if(i%5!=0){
                newa.push_back(i);
            }
        }
        a = newa;
        n = newa.size();
    }

    vector<vector<long double>> dp(n+1, vector<long double>(10,LONG_LONG_MAX));
    vector<vector<vector<int>>> values(n+1, vector<vector<int>>(10));
    dp[0][1] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            
            //if you don't take that value
            int digit = j;
            long double value = dp[i][j]*a[i];
            if(value<dp[i+1][digit]){
                dp[i+1][digit] = value;
                values[i+1][digit] = values[i][j];
                values[i+1][digit].push_back(a[i]);
            }

            //if you do take that value
            digit = (j*a[i])%10;
            value = dp[i][j];
            if(value<dp[i+1][digit]){
                dp[i+1][digit] = value;
                values[i+1][digit] = values[i][j];
            }
            

        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<values[i][j].size()<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> freq(1001);
    for(int i:a){
        freq[i]++;
    }
    for(int i:values[n][k]){
        freq[i]--;
    }
    
    if(a.size()-values[n][k].size()==0||dp[n][k]==LONG_LONG_MAX){
        cout<<-1<<endl;
        return 0;
    }

    cout<<a.size()-values[n][k].size()<<endl;
    for(int i=0;i<1001;i++){
        for(int j=0;j<freq[i];j++){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    

}

/*

also need to understand why you only need at most 4 values

6

11 2 3 4 6 7 8 9


2 4 8 6
1 3 9 7
*/