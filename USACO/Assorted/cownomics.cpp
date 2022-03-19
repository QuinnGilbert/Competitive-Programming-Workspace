#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int value(char c) {
    if(c=='A')return 1;
    if(c=='T')return 2;
    if(c=='C')return 3;
    return 4;
}
// To compute x^y under modulo m
long power(long long x,long long y,long long m){
    if (y == 0)return 1;
    long long p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    
    return (y % 2 == 0) ? p : (x * p) % m;
}
long modInverse(long long a, long long m) {
    return power(a,m-2,m);
}

int main(){
    int n,m;
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");
    fin >> n >> m;
    // cin>>n>>m;
    // char[][] a = new char[n][m];
    // char[][] b = new char[n][m];
    vector<string> a(n);
    vector<string> b(n);
    for(int i=0;i<n;i++) {
        fin>>a[i];
        // cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        // b[i] = f.readLine().toCharArray();
        fin>>b[i];
        // cin>>b[i];
    }

    vector<vector<ll>> prefixa(n,vector<ll>(m+1));
    vector<vector<ll>> prefixb(n,vector<ll>(m+1));
    ll mod = 1000000007;
    ll p = 5;
    for(int i=0;i<n;i++){
        ll pow = 1;
        for(int j=0;j<m;j++){
            prefixa[i][j+1]=(prefixa[i][j]+pow*value(a[i][j]))%mod;
            pow=(pow*p)%mod;
        }
        pow = 1;
        for(int j=0;j<m;j++){
            prefixb[i][j+1]=(prefixb[i][j]+pow*value(b[i][j]))%mod;
            pow=(pow*p)%mod;
        }
    }

    int left=0;
    int right=0;
    int min=1000;
    while(left<m&&right<m){
        unordered_set<ll> spotty;
        for(int i=0;i<n;i++){
            ll hash = ((prefixa[i][right]-prefixa[i][left]+mod)%mod)*modInverse(power(p,left,mod),mod);
            spotty.insert(hash);
            // cout<<hash<<" ";
        }
        // cout<<endl;
        bool check = true;
        for(int i=0;i<n;i++){
            ll hash = ((prefixb[i][right]-prefixb[i][left]+mod)%mod)*modInverse(power(p,left,mod),mod);
            if(spotty.count(hash)){
                check = false;
            }
            // cout<<hash<<" ";
        }
        // cout<<endl;
        if(check){
            if(right-left<min){
                min=right-left;
            }
            left++;
        }else{
            right++;
        }
    }
    fout<<min<<endl;
    // cout<<min<<endl;

}

