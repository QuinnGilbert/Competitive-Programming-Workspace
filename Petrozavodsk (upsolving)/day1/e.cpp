#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int curval=1;
vector<int> p;
vector<int> depth;
//find parents for each node
void traverse(int i, vector<vector<int>> &edge,int d){
    // cout<<i<<endl;
    depth[i]=0;
    for(int j:edge[i]){
        if(j!=p[i]){
            p[j] = i;
            traverse(j,edge,d+1);
        }
    }
    return;
}

struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(const pii &x) const { return __builtin_bswap64((((ll)x.first<<32)|(x.second))*C); }
};



// void solve(int i, vector<vector<int>> &red, vector<vector<int>> &blue, vector<bool> &isblue){
//     // cout<<i<<" "<<p[i]<<endl;
//     if(i==0||p[i]==-1){
//         return;
//     }
//     // cout<<i<<" "<<p[i]<<endl;
//     pair<int,int> edge = minmax(i,p[i]);
//     current.push_back(order[edge]);
//     solve(p[i],red,blue,isblue);
//     p[i]=-1;
//     return;
// }

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,m;
    cin>>n>>m;
    p.resize(n);
    depth.resize(n);
    vector<vector<int>> blue(n);
    vector<vector<int>> red(n);
    vector<bool> isblue(m);
    vector<pair<int,int>> edges(m);
    vector<int> current;
    unordered_map<pair<int,int>,int,chash> order;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        if(c){
            red[a].push_back(b);
            red[b].push_back(a);
        }else{
            isblue[i] = true;
            blue[a].push_back(b);
            blue[b].push_back(a);
        }
        edges[i]=make_pair(a,b);
        order[make_pair(min(a,b),max(a,b))]=i;
    }
    
    // cout<<"Gaming"<<endl;

    p[0] = 0;
    traverse(0,red,0);
    vector<int> result(m);
    vector<int> skip(n,-1);
    for(int i=0;i<m;i++){
        if(result[i]==0){
            if(isblue[i]){
                // cout<<"blue: "<<i<<endl;

                int first,second;
                if(depth[edges[i].first]>depth[edges[i].second]){
                    first = edges[i].first;
                    second = edges[i].second;
                }else{
                    first = edges[i].second;
                    second = edges[i].first;
                }
                while(depth[first]>depth[edges[i].second]){
                    // cout<<"only: "<<first<<endl;
                    if(first!=0)current.push_back(order[minmax(first,p[first])]);
                    first = p[first];
                }
                while(first!=second){
                    // cout<<"first: "<<first<<" "<<p[first]<<"second: "<<second<<" "<<p[second]<<endl;
                    if(first!=0){
                        if(skip[first]!=-1){
                            first = skip[first];
                        }else{
                            current.push_back(order[minmax(first,p[first])]);
                            first = p[first];
                        }
                    }
                    if(second!=0){
                        if(skip[second]!=-1){
                            second = skip[second];
                        }else{
                            current.push_back(order[minmax(second,p[second])]);
                            second = p[second];
                        }
                    }
                }
                int lca = first;
                first = edges[i].first;
                second = edges[i].second;
                while(first!=lca){
                    p[first] = lca;
                    first = p[first];
                }
                while(second!=lca){
                    skip[second] = lca;
                    second = p[second];
                }

                sort(current.begin(),current.end());
                for(int j:current){
                    result[j] = curval++;
                    // cout<<j<<" ";
                }
                // cout<<endl;
                current.clear();
                result[i] = curval++;
                // for(int i=0;i<m;i++){
                //     cout<<result[i]<<" ";
                // }
                // cout<<endl;
            }
        }
    }

    // cout<<"Gaming"<<endl;

    for(int i=0;i<m;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

}

/*
for each node, the red nodes must be less than all other nodes (unless those edged are already connected?)
to make an edge blue, both nodes must have all red edge value less than that node
you want to (greedily?) optimize the value of the first edges

the first value should always be 1 if red and the sum of the number of red edges between those 2 nodes if blue

*/