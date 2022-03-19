#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<long long> a(m+1);
    vector<long long> b(m+1);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x]++;
        b[y]++;
    }
    vector<long long> add(2*m+1);
    vector<long long> sub(2*m+1);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            add[i+j]+=a[i]*a[j];
            sub[i+j]+=b[i]*b[j];
        }
    }
    long long result=0;
    for(int i=0;i<=2*m;i++){
        result+=add[i];
        cout<<result<<"\n";
        result-=sub[i];
    }
}

//going from k to k+1, all pairs ai+aj=k+1 and bi+bj>=k+1 are added and all pairs with bi+bj=k and ai+aj<=k are lost

//we can treat a and b as separate apparently, but why?
/*

it would not be true if we had some b<a (this is key to the proof)

*/