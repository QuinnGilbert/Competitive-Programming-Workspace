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
        int n;
        long long x;
        cin>>n>>x;
        vector<int> a(n);
        map<long long,int> freq;
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        sort(a.begin(),a.end());

        vector<int> keys;
        for(auto i:freq){
            keys.push_back(i.first);
        }

        //assuming that since I use ordered map, keys will be sorted by default
        vector<int> sorted = keys;
        sort(sorted.begin(),sorted.end());
        assert(sorted==keys);

        int count=0;
        for(int i:keys){
            while(freq[i]){
                if(freq[i*x]){
                    freq[i*x]--;
                }else{
                    count++;
                }
                freq[i]--;
            }
        }
        cout<<count<<endl;
    }

}

//if x was allowed to be 1 this would have needed an edge case
