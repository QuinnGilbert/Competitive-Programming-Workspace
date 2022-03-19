#include <bits/stdc++.h>

using namespace std;

bool check(unordered_map<char,int> &val, unordered_map<char,char> &sign, vector<vector<int>> &res, vector<vector<char>> &a, unordered_map<char,int> &size){
    unordered_map<char,vector<int>> g;
    for(auto i:val){
        g[i.first] = vector<int>();
    }
    int n = a.size();
    vector<vector<bool>> row(n,vector<bool>(10));
    vector<vector<bool>> col(n,vector<bool>(10));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(res[i][j]!=0){
                g[a[i][j]].push_back(res[i][j]);
                if(row[i][res[i][j]]||col[j][res[i][j]]){
                    return false;
                }
                row[i][res[i][j]]=true;
                col[j][res[i][j]]=true;
            }
        }
    }
    for(auto i:g){
        if(i.second.size()==size[i.first]){
            if(sign[i.first]=='/'){
                if(!(i.second[0]/i.second[1]==val[i.first]||i.second[1]/i.second[0]==val[i.first])){
                    return false;
                }
            }
            if(sign[i.first]=='-'){
                if(!(i.second[0]-i.second[1]==val[i.first]||i.second[1]-i.second[0]==val[i.first])){
                    return false;
                }
            }
            if(sign[i.first]=='*'){
                int total=1;
                for(int j:i.second){
                    total*=j;
                }
                if(total!=val[i.first]) return false;
            }
            if(sign[i.first]=='+'){
                int total=0;
                for(int j:i.second){
                    total+=j;
                }
                if(total!=val[i.first]) return false;
            }
            if(sign[i.first]=='.'){
                if(i.second[0]!=val[i.first]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve(unordered_map<char,int> &val, unordered_map<char,char> &sign, vector<vector<int>> &res, vector<vector<char>> &a, unordered_map<char,int> &size, int index){
    int n = a.size();
    if(index==n*n) return true;
    cout<<index<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    int r = index/n;
    int c = index%n;
    for(int i=1;i<=n;i++){
        res[r][c] = i;
        if(check(val,sign,res,a,size)){
            if(solve(val,sign,res,a,size,index+1)){
                return true;
            }
        }
    }
    res[r][c]=0;
    return false;
}

int main(){
    int testcase=0;
    while(true){
        testcase++;
        int n,m;
        cin>>n;
        if(n==0)break;
        cin>>m;
        vector<vector<char>> a(n,vector<char>(n));
        unordered_map<char,int> size;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                size[a[i][j]]++;
            }
        }
        unordered_map<char,int> val;
        unordered_map<char,char> sign;
        for(int i=0;i<m;i++){
            char c;
            int x;
            char s;
            cin>>c>>x>>s;
            val[c]=x;
            sign[c]=s;
        }
        vector<vector<int>> res(n,vector<int>(n));
        solve(val,sign,res,a,size,0);
        cout<<"KenKen Puzzle #"<<testcase<<":"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<res[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

/*
2 4
ab
cd
a 1 .
b 2 .
c 2 .
d 1 .

aabccd
*/