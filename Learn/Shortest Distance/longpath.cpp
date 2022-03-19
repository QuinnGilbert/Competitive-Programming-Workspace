#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> &in, vector<int> &result, vector<vector<pair<int,int>>> &e, int i){
    if(in[i]==0||in[i]==1){
        result.push_back(i);
        for(auto j:e[i]){
            dfs(in,result,e,j.first);
        }
    } 
    in[i]--;
}

int main(){

    int t;
    cin>>t;
    for(int c=0;c<t;c++){
        int n,e;
        cin>>n>>e;
        vector<vector<pair<int,int>>> edge(n);
        vector<int> in(n);
        for(int i=0;i<e;i++){
            int a,b,d;
            cin>>a>>b>>d;
            in[b]++;
            edge[a].emplace_back(b,d);
        }
        vector<int> topsort;
        dfs(in,topsort,edge,0);
        // if(topsort.size()==0){
        //     cout<<"CHECK"<<endl;
        // }
        // for(int i:topsort){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        unordered_map<int,int> v;
        for(int i=0;i<topsort.size();i++){
            v[topsort[i]]=i;
        }
        vector<int> small(topsort.size(),INT_MAX);
        vector<int> large(topsort.size());
        small[0]=0;
        large[0]=0;
        for(int i=0;i<topsort.size();i++){
            for(auto j:edge[topsort[i]]){
                small[v[j.first]] = min(small[v[j.first]],small[i]+j.second);
                large[v[j.first]] = max(large[v[j.first]],large[i]+j.second);
            }
            // cout<<small[i]<<" "<<large[i]<<endl;
            if(topsort[i]==n-1){
                cout<<small[i]<<" "<<large[i]<<endl;
            }
        }
    }
}

/*
2
6 7
0 1 1
1 2 2
2 5 3
1 5 6
0 3 5
3 4 6
4 5 7
3 3
0 1 7
0 2 19
1 2 8
*/