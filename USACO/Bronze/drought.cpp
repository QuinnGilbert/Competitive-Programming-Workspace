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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int min = INT_MAX;
        for(int i=100;i>=0;i--){
            bool check = true;
            vector<int> b = a;
            int count=0;
            for(int j=0;j<n-1;j++){
                if(b[j]<i) check = false;
                while(b[j]>i){
                    b[j]--;
                    b[j+1]--;
                    count+=2;
                }
            }
            // cout<<i<<endl;
            // for(int j=0;j<n;j++){
            //     cout<<b[i]<<" ";
            // }
            // cout<<endl;
            if(check&&b[n-1]==i){
                min = count;
                break;
            }
        }
        if(min==INT_MAX){
            cout<<-1<<endl;
        }else{
            cout<<min<<endl;
        }
    }

}

/*
for even values any ending value under the first valid one will work (can binary search, or maybe get it easier)
for odd values only 1 ending value will work

if a[0]>a[1] it is impossible
if a[0]=a[1] both can be mostly ignored but final value must be less than or equal to a[0]
if a[0]<a[1]:
    if 

the maximal value must be equalon both sides (maybe also every local max)
*/