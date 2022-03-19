#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
using P = pair<long long, long long>;

// template<class PA, class PB, class PC> ostream& operator<<(ostream &os, const tuple<PA, PB, PC>& p) {
//     return os << "<" << gets<0>(p) << "," << gets<1>(p) <<","<< gets<2>(p)<<">";
// }
struct hsh {
	size_t operator()(const P &p) const {
		return p.first * 239 + p.second;
	}
};

struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(const pii &x) const { return __builtin_bswap64((((ll)x.first<<32)|(x.second))*C); }
};

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;cin>>n;
    int xg,yg;cin>>xg>>yg;

    int m = n/2;
    n = n-m;

    vector<pair<long long,long long>> a(n);
    vector<pair<long long,long long>> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<m;i++){
        cin>>b[i].first>>b[i].second;
    }

    // vector<tuple<long long,long long,long long>> first;
    vector<long long> fx;
    vector<long long> fy;
    vector<long long> fc;
    unordered_map<P,map<long long, long long> ,hsh> second;
    for(int bitmask=0;bitmask<1<<n;bitmask++){
        long long x=0;
        long long y=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(bitmask&1<<i){
                x+=a[i].first;
                y+=a[i].second;
                count++;
            }
        }
        // first.emplace_back(x,y,count);
        fx.push_back(x);
        fy.push_back(y);
        fc.push_back(count);
    }
    // cout<<"CHECK"<<endl;

    for(int bitmask=0;bitmask<1<<m;bitmask++){
        long long x=0;
        long long y=0;
        int count=0;
        for(int i=0;i<m;i++){
            if(bitmask&1<<i){
                x+=b[i].first;
                y+=b[i].second;
                count++;
            }
        }
        // second[to_string(x)+" "+to_string(y)+" "+to_string(count)]++;
        second[make_pair(x,y)][count]++;
    }

    // cout<<"CHECK"<<endl;
    // for(auto point:first){
    //     cout<<"("<<point.first<<", "<<point.second<<") ";
    // }
    // cout<<endl;

    n = n+m;
    vector<long long> result(n+1);
    for(int j=0;j<fx.size();j++){
        // // if(index++%10000==0)cout<<index<<endl;
        long long x = fx[j];
        long long y = fy[j];
        long long count = fc[j];
        // auto &curmap = second[make_pair(xg-x,yg-y)];
        
        auto it = second.find(make_pair(xg-x,yg-y));
		// if (it != end(first_half)) {
		// 	for (const auto &[num2, ways] : it->second) {
		// 		ans[num + num2] += ways;
		// 	}
		// }
        // for(int i=count;i<=n;i++){
        //     // result[i]+=second[to_string(xg-x)+" "+to_string(yg-y)+" "+to_string(i-count)];
        //     // result[i]+=second[make_pair(xg-x,yg-y)][i-count];
        //     result[i]+=curmap[i-count];
        // }
        // if(it!=end(second)){
        //     for(auto [num2,ways]:it->second){
        //         result[count+num2]+=ways;
        //     }
        // }
    }

    // cout<<"CHECK"<<endl;

    for(int i=1;i<=n;i++){
        cout<<result[i]<<"\n";
    }
}

/*
brute force over only half the values and store their locations and 
*/