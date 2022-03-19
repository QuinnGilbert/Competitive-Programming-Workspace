#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = int(2e9);

template<class T> ostream& operator<<(ostream& os, vector<T>& vec) {
    cout << "[";
    for(auto x : vec) os << x << " ";
    os << "]";
    return os;
}

struct node{
    int lo, hi, mid;
    ll minn = 0, lazy = 0;
    node *left, *right;
    node(int l, int r): lo(l), hi(r), mid(l+r>>1) {
        if(l == r) return;
        left = new node(l, mid), right = new node(mid+1, r);
    }

    ll val() {
        return minn+lazy;
    }

    void prop() {
        if(lazy) {
            left->lazy += lazy;
            right->lazy += lazy;
            lazy = 0;
            minn = min(left->val(), right->val());
        }
    }

    void add(int l, int r, ll x) {
        if(r < lo || l > hi) return;
        if(l <= lo && r >= hi){
            lazy += x; return;
        }
        prop();
        left->add(l, r, x); right->add(l, r, x);
        minn = min(left->val(), right->val());
    }

    ll query(int l, int r) {
        if(r < lo || l > hi) return oo;
        if(l <= lo && r >= hi) return val();
        prop();
        return min(left->query(l, r), right->query(l, r));
    }
};

struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    node *tree;
    HLD(vector<vi> adj_)
    : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N), pos(N), tree(new node(0, N)) {
        dfsSz(0); 
        dfsHld(0);
    }
    void dfsSz(int v){
        if(par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
        for(int &u : adj[v]) {
            par[u] = v, depth[u] = depth[v]+1;
            dfsSz(u);
            siz[v] += siz[u];
            if(siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }

    void dfsHld(int v) {
        pos[v] = tim++;
        for(int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template<class B> void process(int u, int v, B op) {
        for(; rt[u] != rt[v]; v = par[rt[v]]) {
            if(depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(pos[rt[v]], pos[v]+1);
        }
        if(depth[u] > depth[v]) swap(u, v);
        op(pos[u], pos[v]+1);
    }
    void modifyPath(int u, int v, ll val) {
        // cout << " modpath " << u << "-" << v << " of " << val << endl;
        process(u, v, [&](int l, int r) { 
            // cout << "Tree add from " << l << " to " << r << " of " << val << endl; 
            tree->add(l, r-1, val);
        });
    }
    ll queryPath(int u, int v) {
        ll res = oo;
        process(u, v, [&](int l, int r) {
            res = min(res, tree->query(l, r-1));
        });
        return res;
    }
    ll querySubtree(int v) {
        return tree->query(pos[v], pos[v] + siz[v]-1);
    }
};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n; cin >> n; 
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++) { int p; cin >> p; graph[p-1].push_back(i+1); graph[i+1].push_back(p-1); }
    vector<ll> tem(n), qst(n);
    for(auto &x : tem) cin >> x;
    for(auto &x : qst) cin >> x;

    HLD hld(graph);
    
    vector<int> ssum(n);
    auto dfs1 = [&](int u, int par, auto &&dfs1)->int{
        hld.modifyPath(u, 0, tem[u]-qst[u]);
        for(auto x : graph[u]) if(x != par) ssum[u] += dfs1(x, u, dfs1);
        return ssum[u] += tem[u]-qst[u];
    }; dfs1(0, 0, dfs1);

    int q; cin >> q;
    cout << (hld.querySubtree(0))<<endl;
    while(q--){
        int t, i, x; cin >> t >> i >> x; i--;
        if(t == 1){
            int delta = x - tem[i]; tem[i] = x;
            hld.modifyPath(i, 0, delta);
        } else{
            int delta = x - qst[i]; qst[i] = x;
            hld.modifyPath(i, 0, -delta);
        }
        cout << (hld.querySubtree(0))<<endl;
    }


    return 0;
}