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
        vector<pair<int,int>> sorter(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            sorter[i] = make_pair(a[i],i);
        }
        sort(sorter.begin(),sorter.end());
        vector<int> place(n);
        for(int i=0;i<n;i++){
            place[sorter[i].second]=i;
        }

        bool even=false;
        bool odd=false;
        bool check=true;
        for(int i=0;i<n;i++){
            if(place[i]<i){
                if(a[i]%2==0&&even){

                }
            }else{
                if(a[i]%2==0){
                    even=true;
                }else{
                    odd=true;
                }
            }
        }

    }

}

/*

if i<j and a[i]>a[j] and both values must move to the left, it is impossible

if we ever have a decreasing sequence of 3 (3 2 1) then it is impossible?

*/