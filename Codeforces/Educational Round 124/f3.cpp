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

    

}

/*

precompute into a segment tree the sum of every prefix for every time value (since last monster) up to sqrt(n)
(If we are precomputing can we just use a prefix array instead of a segment tree?)

binary search on where each monster dies and set that 


*/