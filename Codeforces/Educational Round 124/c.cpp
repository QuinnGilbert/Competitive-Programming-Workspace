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

        auto getMinIndex = [](long long x, vector<long long> a)->int{
            sort(a.begin(),a.end());
            //maybe I should return 0 as default
            int index=0;
            for(int i=0;i<a.size();i++){
                if(a[i]<x){
                    index=i;
                }
            }
            return index;
        };
        auto getMin = [](long long x, vector<long long> a, int dont)->long long{
            long long min = INT_MAX;
            for(int i=0;i<a.size();i++){
                if(i==dont)continue;
                if(abs(a[i]-x)<min) min = abs(a[i]-x);
            }
            return min;
        };

        int ai = getMinIndex(a[0],b);
        int bi = getMinIndex(b[0],a);
        long long result = abs(a[0]-b[ai])+abs(b[0]-a[bi])+getMin(a[n-1],b,ai)+getMin(b[n-1],a,bi);
        long long result = abs(a[0]-b[ai+1])+abs(b[0]-a[bi])+getMin(a[n-1],b,ai+1)+getMin(b[n-1],a,bi);
        long long result = abs(a[0]-b[ai])+abs(b[0]-a[bi+1])+getMin(a[n-1],b,ai)+getMin(b[n-1],a,bi+1);
        long long result = abs(a[0]-b[ai+1])+abs(b[0]-a[bi+1])+getMin(a[n-1],b,ai+1)+getMin(b[n-1],a,bi+1);

        result = min(result, abs(a[0]-b[0])+abs(b[n-1]-a[n-1]));

        result = min(result, abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));

        result = min(result, abs(a[0]-b[0])+getMin(a[n-1],b,0)+getMin(b[n-1],a,0));



        result = min(result, abs(a[0]-b[n-1])+getMin(a[n-1],b)+getMin(b[0],a));
        result = min(result, abs(a[n-1]-b[n-1])+getMin(a[0],b)+getMin(b[0],a));
        result = min(result, abs(a[n-1]-b[0])+getMin(a[0],b)+getMin(b[n-1],a));

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

also 

find the index of the last value that is less than the edge
will either use that value and exlude from the other search, or usethe next value and exclude that from the other search (never need to do both)

*/