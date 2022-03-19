#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;cin>>n;
    vector<pair<int,int>> b(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>b[i].first>>b[i].second;
        a[i] = b[i].first;
    }

    int sum=0;
    vector<int> prevTime(n);
    int q;cin>>q;
    for(int query=0;query<q;query++){
        int start,x;cin>>start>>x;
        for(int i=0;i<n;i++){
            a[i] = min(b[i].first,a[i]+(start+i-prevTime[i])*b[i].second);
            int diff = min(x,a[i]);
            x-=diff;
            a[i]-=diff;
            prevTime[i]=start+i;
        }
        sum+=x;
    }
    cout<<sum<<endl;

}



/*
3
5 1
7 4
4 2
4
0 14
1 10
3 16
10 16

1 4 2
5 7 4
0: 1 7 4
-----9--
1: 1 4 4
-----9-2
2: 2 4 4
-------5
3:
*/