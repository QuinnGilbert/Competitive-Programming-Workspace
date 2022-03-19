#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string,int> count;
    int ma = 0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        count[s]++;
        ma = max(ma,count[s]);
    }
    vector<string> res;
    for(auto i : count){
        if(i.second==ma)res.push_back(i.first);
    }
    sort(res.begin(),res.end());
    for(string i:res){
        cout << i << endl;
    }
}
