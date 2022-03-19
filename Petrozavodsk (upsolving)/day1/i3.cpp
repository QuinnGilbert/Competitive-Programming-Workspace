#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	//Need to set val to 0 bc you are not setting values from HLD with set(), and you want the sum to start at 0 - Tyler HM
	ll lo, hi, mset = inf, madd = 0, val  = 0;
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

template <bool VALS_EDGES> struct HLD {
	ll N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(ll v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (ll& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(ll v) {
		pos[v] = tim++;
		for (ll u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(ll u, ll v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(ll u, ll v, ll val) {
		process(u, v, [&](ll l, ll r) { tree->add(l, r, val); });
	}
	ll queryPath(ll u, ll v) { // Modify depending on problem
		ll res = -1e9;
		process(u, v, [&](ll l, ll r) {
				res = max(res, tree->query(l, r));
		});
		return res;
	}
	ll querySubtree(ll v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;
    vector<vector<ll>> edge(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        p--;
        edge[p].push_back(i);
        edge[i].push_back(p);
    }

    HLD<false> hld(edge);

    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        hld.modifyPath(i,0,b[i]-a[i]);
    }
    cout<< ((hld.querySubtree(0)) > 0? "No":"Yes") <<endl;
	// cout<<(hld.querySubtree(0)+inf)<<endl;

    // vector<int> ssum(n);
    // auto dfs1 = [&](int u, int par, auto &&dfs1)->int{
    //     hld.modifyPath(u, 0, a[u]-b[u]);
    //     for(auto x : edge[u]) if(x != par) ssum[u] += dfs1(x, u, dfs1);
    //     return ssum[u] += a[u]-b[u];
    // }; dfs1(0, 0, dfs1);

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll type,v,x;
        cin>>type>>v>>x;
        v--;
        if(type==1){
            ll diff = x-a[v];
            a[v]=x;
            hld.modifyPath(v,0,-diff);
        }else{
            ll diff = x-b[v];
            b[v]=x;
            hld.modifyPath(v,0,diff);
        }
        cout<<((hld.querySubtree(0))>0? "No":"Yes")<<endl;
		// cout<<(hld.querySubtree(0)+inf)<<endl;
    }


}