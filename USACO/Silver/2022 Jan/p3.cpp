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

    int n,m;
    cin>>m>>n;
    vector<pair<int,int>> prefs(m);
    vector<vector<pair<int,int>>> edge(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].emplace_back(b,i);
        edge[b].emplace_back(a,i);
        prefs[i] = make_pair(a,b);
    }

    //split into connected components
    vector<bool> v(n);
    vector<vector<int>> groups;
    auto traverse = [&](int i, auto &&traverse)->void{
        if(v[i]) return;
        v[i]=true;
        groups[groups.size()-1].push_back(i);
        for(auto[j,index] :edge[i]){
            traverse(j,traverse);
        }
    };

    for(int i=0;i<n;i++){
        if(!v[i]){
            groups.push_back(vector<int>());
            traverse(i,traverse);
        }
    }
    
    // for(auto i:groups){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    v = vector<bool>(n);
    vector<bool> touched(n);
    vector<bool> edgev(m);
    auto findCycle = [&](int i, auto &&findCycle)->int{
        // cout<<i<<endl;
        v[i] = true;
        touched[i] = true;
        bool parent=false; //to account for duplicate edges (does not work)
        for(auto[j,index] :edge[i]){
            if(edgev[index]) continue;
            if(touched[j]){
                return index;
            }
            if(!v[j]){
                edgev[index]=true;
                int x = findCycle(j, findCycle);
                if(x!=-1){
                    return x;
                }
            }
        }
        return -1;
    };

    //process each connected component
    vector<int> result;
    vector<bool> used(n);
    vector<bool> served(m);
    auto dfs = [&](int i, auto &&dfs)->void{
        used[i] = true;
        for(auto[j,index] :edge[i]){
            if(!served[index]&&!used[j]){
                result.push_back(index);
                served[index] = true;
                dfs(j,dfs);
            }
        }
    };

    for(auto i:groups){
        // cout<<"started "<<i[0]<<endl;
        int start = findCycle(i[0],findCycle);
        // cout<<"Start "<<start<<endl;
        if(start==-1){
            //the component is a tree
            for(int j:i){
                if(!used[j]){
                    for(auto[k,index]: edge[j]){
                        if(prefs[index].first==j && !served[index]){
                            result.push_back(index);
                            served[index]=true;
                            dfs(prefs[index].first,dfs);
                        }
                    }
                }
            }
        }else{
            result.push_back(start);
            served[start] = true;
            dfs(prefs[start].first,dfs);
        }
    }
    
    int count=0;
    for(int i=0;i<m;i++){
        if(!served[i]){
            count++;
            result.push_back(i);
        }
    }

    cout<<count<<endl;
    assert(result.size()==m);
    for(int i:result){
        cout<<i+1<<endl;
    }

}

/*

split the preferences into several connected components and solve them all separately

if a component is a tree, we can choose any edge to start with, but must afterwards follow it by immediately taking any edge which 
only has one more option

if the component has n edges, never remove a node that separates the graph into a component with more nodes than edges (and vice-versa)
you should always be fine if you remove a node that is part of a cycle (because you are not separating the graph)

if the component has more than n edges, you still cannot separate the graph into a component with more nodes than edges
You can still just remove any node in a cycle and that should be enough be enoug to fully traverse the graph

*/