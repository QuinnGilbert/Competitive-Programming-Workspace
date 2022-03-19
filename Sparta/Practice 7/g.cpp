#include <bits/stdc++.h>

using namespace std;

struct Node{
    vector<int> e;
    map<int,int> value;
    Node(){}
};

int value=1;

int add(map<map<int,int>, int> &name, map<int,int> &v){
    if(name.count(v)){
        return name[v];
    }else{
        name[v]=value++;
        return name[v];
    }
}

int dfs(vector<Node> &g, map<map<int,int>,int> &name,int index, int p){
    for(int i:g[index].e){
        if(i!=p){
            g[index].value[dfs(g,name,i,index)]++;
        }
    }
    return add(name,g[index].value);
}

unordered_set<int> result;
void dfs2(vector<Node> &g, map<map<int,int>,int> &name,int index, int p){
    if(p==-1){
        result.insert(name[g[index].value]);
    }else{
        int curName = name[g[index].value];
        g[p].value[curName]--;
        if(g[p].value[curName]==0) g[p].value.erase(curName);
        int pName = add(name,g[p].value);
        g[p].value[curName]++;
        g[index].value[pName]++;
        result.insert(add(name,g[index].value));
    }
    for(int i:g[index].e){
        if(i!=p){
            dfs2(g,name,i,index);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<Node> g(n);
    map<map<int,int>,int> name;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].e.push_back(b);
        g[b].e.push_back(a);
    }

    dfs(g,name,0,-1);
    dfs2(g,name,0,-1);
    cout<<result.size()<<endl;


}



//dfs and backprop from some root node so that each node has an up value
//the value rooted at each node would recalculate the parent without
//that child (using it's full value as a root node)