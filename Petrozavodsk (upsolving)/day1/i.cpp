#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

template<class T> ostream& operator<<(ostream& os, vector<T>& vec) {
    cout << "[";
    for(auto x : vec) os << x << " ";
    os << "]";
    return os;
}

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = 0, madd = 0, val = inf;
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(ll L, ll R) {
		if (R <= lo || hi <= L) {
            return inf;
            cout<<"Check"<<endl;
        }
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
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
			val = min(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};



// const int oo = int(2e9);

// struct node{
//     int lo, hi, mid;
//     ll minn = 0, lazy = 0;
//     node *left, *right;
//     node(int l, int r): lo(l), hi(r), mid(l+r>>1) {
//         if(l == r) return;
//         left = new node(l, mid), right = new node(mid+1, r);
//     }

//     ll val() {
//         return minn+lazy;
//     }

//     void prop() {
//         if(lazy) {
//             left->lazy += lazy;
//             right->lazy += lazy;
//             lazy = 0;
//             minn = min(left->val(), right->val());
//         }
//     }

//     void add(int l, int r, ll x) {
//         if(r < lo || l > hi) return;
//         if(l <= lo && r >= hi){
//             lazy += x; return;
//         }
//         prop();
//         left->add(l, r, x); right->add(l, r, x);
//         minn = min(left->val(), right->val());
//     }

//     ll query(int l, int r) {
//         if(r < lo || l > hi) return oo;
//         if(l <= lo && r >= hi) return val();
//         prop();
//         return min(left->query(l, r), right->query(l, r));
//     }
// };

struct HLD {
	ll N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u], pos[v] + 1);
	}
	void modifyPath(int u, int v, ll val) {
		process(u, v, [&](int l, int r) { tree->add(l, r, val); });
	}
	int queryPath(int u, int v) { // Modify depending on problem
		int res = 1e9;
		process(u, v, [&](int l, int r) {
				res = min(res, tree->query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v], pos[v] + siz[v] - 1);
	}
};

// struct HLD {
//     int N, tim = 0;
//     vector<vi> adj;
//     vi par, siz, depth, rt, pos;
//     node *tree;
//     HLD(vector<vi> adj_)
//     : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N), pos(N), tree(new node(0, N)) {
//         dfsSz(0); 
//         dfsHld(0);
//     }
//     void dfsSz(int v){
//         if(par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
//         for(int &u : adj[v]) {
//             par[u] = v, depth[u] = depth[v]+1;
//             dfsSz(u);
//             siz[v] += siz[u];
//             if(siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
//         }
//     }

//     void dfsHld(int v) {
//         pos[v] = tim++;
//         for(int u : adj[v]) {
//             rt[u] = (u == adj[v][0] ? rt[v] : u);
//             dfsHld(u);
//         }
//     }
//     template<class B> void process(int u, int v, B op) {
//         for(; rt[u] != rt[v]; v = par[rt[v]]) {
//             if(depth[rt[u]] > depth[rt[v]]) swap(u, v);
//             op(pos[rt[v]], pos[v]+1);
//         }
//         if(depth[u] > depth[v]) swap(u, v);
//         op(pos[u], pos[v]+1);
//     }
//     void modifyPath(int u, int v, ll val) {
//         // cout << " modpath " << u << "-" << v << " of " << val << endl;
//         process(u, v, [&](int l, int r) { 
//             // cout << "Tree add from " << l << " to " << r << " of " << val << endl; 
//             tree->add(l, r-1, val);
//         });
//     }
//     ll queryPath(int u, int v) {
//         ll res = oo;
//         process(u, v, [&](int l, int r) {
//             res = min(res, tree->query(l, r-1));
//         });
//         return res;
//     }
//     ll querySubtree(int v) {
//         return tree->query(pos[v], pos[v] + siz[v]-1);
//     }
// };

int main(){

    int n;
    cin>>n;
    vector<vector<int>> edge(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        p--;
        edge[p].push_back(i);
        edge[i].push_back(p);
    }
    HLD hld(edge);

    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        hld.modifyPath(i,0,a[i]-b[i]);
    }
    cout<<(hld.querySubtree(0)<0? "No":"Yes")<<endl;
	cout<<hld.querySubtree(0)<<endl;

    // vector<int> ssum(n);
    // auto dfs1 = [&](int u, int par, auto &&dfs1)->int{
    //     hld.modifyPath(u, 0, a[u]-b[u]);
    //     for(auto x : edge[u]) if(x != par) ssum[u] += dfs1(x, u, dfs1);
    //     return ssum[u] += a[u]-b[u];
    // }; dfs1(0, 0, dfs1);

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type,v,x;
        cin>>type>>v>>x;
        v--;
        if(type==1){
            ll diff = x-a[v];
            a[v]=x;
            hld.modifyPath(v,0,diff);
        }else{
            ll diff = x-b[v];
            b[v]=x;
            hld.modifyPath(v,0,-diff);
        }
        cout<<(hld.querySubtree(0)<0? "No":"Yes")<<endl;
		cout<<hld.querySubtree(0)<<endl;
    }

    // int q; cin >> q;
    // cout << (hld.querySubtree(0) )<<endl;
    // while(q--){
    //     int t, i, x; cin >> t >> i >> x; i--;
    //     if(t == 1){
    //         int delta = x - a[i]; a[i] = x;
    //         hld.modifyPath(i, 0, delta);
    //     } else{
    //         int delta = x - b[i]; b[i] = x;
    //         hld.modifyPath(i, 0, -delta);
    //     }
    //     cout << (hld.querySubtree(0) )<<endl;
    // }

}