#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
int current=0;

int count(int i){
    if(tree[i].size()==0){
        return 2;
    }
    for(int j:tree[i]){

    }

    current++;
    return current+
}

int main(){

    int n;
    cin>>n;
    tree.resize(n);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        x--;
        tree[x].push_back(i);
    }

}