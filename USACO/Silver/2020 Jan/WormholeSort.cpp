#include <bits/stdc++.h>

using namespace std;

vector<bool> v;
unordered_set<int> myindex;
unordered_set<int> pindex;
vector<vector<pair<int,int>>> e;
vector<int> p;
int c;

void dfs(int i,int x){
    // cout<<"My index: ";
    // for(int j:myindex){
    //     cout<<j<<" ";
    // }
    // cout<<endl;
    // cout<<i<<" "<<p[i]<<" "<<x<<endl;
    v[i]=true;
    myindex.insert(i);
    pindex.insert(p[i]);
    if(pindex.count(i)){
        // cout<<i<<" "<<p[i]<<x<<endl;
        c++;
        pindex.erase(i);
        myindex.erase(i);
    }
    if(myindex.count(p[i])){
        pindex.erase(p[i]);
        myindex.erase(p[i]);
        c++;
    }
    for(auto j:e[i]){
        if(j.second>=x&&!v[j.first]){
            // cout<<j.first<<" "<<j.second<<" "<<x<<endl;
            dfs(j.first,x);
        }
    }
}

int main(){

    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    int n,m;
    fin>>n>>m;
    p.resize(n);
    v.resize(n);
    e.resize(n);
    bool inOrder = true;
    for(int i=0;i<n;i++){
        fin>>p[i];
        p[i]--;
        if(p[i]!=i) inOrder = false;
    }
    if(inOrder){
        fout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        fin>>a>>b>>w;
        a--;b--;
        e[a].emplace_back(b,w);
        e[b].emplace_back(a,w);
    }
    // cout<<"CHECK"<<endl;

    int low = 0;
    int high = 1'000'000'001;
    while(low<high-1){
        // cout<<low<<" "<<high<<endl;
        int mid = (low+high)/2;
        c=0;
        fill(v.begin(),v.end(),false);
        for(int i=0;i<n;i++){
            if(!v[i]){
                myindex.clear();
                pindex.clear();
                dfs(i,mid);
            }
        }
        // cout<<"Count: "<<c<<endl;
        if(c==n){
            low=mid;
        }else{
            high=mid;
        }
    }
    fout<<low<<endl;
    // cout<<low<<endl;
    fout.close();
}