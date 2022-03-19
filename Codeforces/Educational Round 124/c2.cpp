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

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        auto getMin = [](long long x, vector<long long> a)->long long{
            long long min = INT_MAX;
            for(int i=0;i<a.size();i++){
                if(abs(a[i]-x)<min) min = abs(a[i]-x);
            }
            return min;
        };

        long long result = getMin(a[0],b)+getMin(a[n-1],b)+getMin(b[0],a)+getMin(b[n-1],a);
        result = min(result, abs(a[0]-b[0])+abs(b[n-1]-a[n-1]));
        result = min(result, abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));

        result = min(result, abs(a[0]-b[0])+getMin(a[n-1],b)+getMin(b[n-1],a));
        // result = min(result, abs(a[0]-b[0])+getMin(a[n-1],b)+getMin(b[n-1],a)+getMin(a[n-1],b));
        // result = min(result, abs(a[0]-b[n-1])+getMin(a[n-1],b)+getMin(b[0],a));
        result = min(result, abs(a[n-1]-b[n-1])+getMin(a[0],b)+getMin(b[0],a));
        // result = min(result, abs(a[n-1]-b[0])+getMin(a[0],b)+getMin(b[n-1],a));

        cout<<result<<endl;
    }

}

/*

must connect the 4 ends somehow
if the edges connect to eachother, it is easy

there are only a few possibilities:
a,b,c,d


a1,b1,a2,b2
(a1,b1)(a2,b2)
(a1,b2)(a2,b1)
(a1,b1)a2,b2
(a1,b2)a2,b1
(a2,b2)a1,b1
(a2,b1)a1,b2



*/