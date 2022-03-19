#include <bits/stdc++.h>

using namespace std;

unordered_map<string,vector<pair<int,string>>> edge;
unordered_map<string,vector<int>> value;
vector<int> topsort;
unordered_set<string> v;

void dfs(string s){
    v.insert(s);
    for(auto i:edge[s]){
        if(!v.count(i.second)){
            dfs(i.second);
        }
    }
    // cout<<s<<endl;
    sort(value[s].begin(),value[s].end(),greater<int>());
    for(int i:value[s]){
        topsort.push_back(i);
    }
}

int main(){

    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        edge.clear();
        topsort.clear();
        v.clear();
        value.clear();
        unordered_map<string,int> order;
        for(int i=0;i<n;i++){
            string a,b;
            int f;
            cin>>a>>b>>f;
            edge[a].emplace_back(f,b);
            value[b].push_back(f);

            if(!order.count(b)){
                order[b] = f;
            }else{
                order[b] = min(order[b],f);
            }
            if(!order.count(a)){
                order[a] = INT_MAX;
            }

            // nodes.push_back(a);
            // nodes.push_back(b);
        }
        vector<pair<int,string>> nodes;
        for(auto i:order){
            if(i.second==INT_MAX)nodes.emplace_back(0,i.first);
            else nodes.emplace_back(i.second,i.first);
        }
        sort(nodes.begin(),nodes.end(),greater<pair<int,string>>());
        // for(auto i:nodes){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        for(auto s:nodes){
            sort(edge[s.second].begin(),edge[s.second].end(),greater<pair<int,string>>());
        }
        for(auto s:nodes){
            if(!v.count(s.second)){
                // cout<<"CHECK"<<s.second<<endl;
                dfs(s.second);
            }
        }
        reverse(topsort.begin(),topsort.end());
        for(int i:topsort){
            // if(i!=0){
                cout<<i<<" ";
            // }
        }
        cout<<endl;

    }

}