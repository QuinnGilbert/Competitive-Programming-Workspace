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


    long long MOD = 1000000007;
    vector<int> unique;
    unique.push_back(0);
    vector<int> sequence;
    sequence.push_back(0);
    for(int i=0;i<15;i++){
        long long v=2;
        while(true){
            bool check = true;
            unordered_set<int> test;
            for(int j:unique){
                if(test.count((j+v)%MOD)) {
                    check = false;
                    break;
                }
                test.insert((j+v)%MOD);
                if(test.count((j*v)%MOD)){
                    check = false;
                    break;
                }
                test.insert((j*v)%MOD);
            }
            if(check){
                unique.clear();
                for(int j:test){
                    unique.push_back(j);
                }
                break;
            }
            v++;
        }
        sequence.push_back(v);
        for(int j:sequence){
            cout<<j<<" ";
        }
        cout<<endl;
    }


}

//0 2 3 2 4 7 9 17 15 18 7 61 25 64 85 49