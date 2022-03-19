#include <bits/stdc++.h>

using namespace std;

void generate(int index, int max, int n, int sum, string res, vector<string> &list){
    // cout<<index<<endl;
    if(sum>42)return;
    if(index==n){
        swap(res[n-1],res[n-2]);
        if(sum==42)list.push_back(res);
        return;
    }
    for(int i=0;i<=max;i++){
        char c = i+'a';
        if(c=='a'||c=='i'||c=='o'||c=='u'||c=='e'||c=='y')continue;
        generate(index+1,i-1,n,sum+i+1,res+c,list);
    }
}

int main(){
    while(true){
        int n;
        cin>>n;
        if(n==42)break;
        vector<string> list;
        generate(0,25,n,0, "",list);
        cout<<"XKCD-like name(s) of length: "<<n<<endl;
        sort(list.begin(),list.end());
        for(string s:list){
            cout<<s<<endl;
        }
        if(list.size()==0)cout<<"Mostly Harmless"<<endl;
    }
    cout<<"The answer to life, the universe and everything!"<<endl;
}

