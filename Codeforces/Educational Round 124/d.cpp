#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

struct State{

    int x,y,ax,ay,d;
    State(int a,int b,int c,int D,int e){
        x=a;
        y=b;
        ax=c;
        ay=D;
        d=e;
    }

};

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;cin>>n;
    vector<pair<int,int>> a(n);
    map<pair<int,int>, int> index;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        index[a[i]] = i;
    }

    vector<bool> v(n);
    vector<pair<int,int>> result(n);
    deque<State> q;
    vector<vector<int>> dirs= {{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<n;i++){
        for(auto d:dirs){
            int x = a[i].first+d[0];
            int y = a[i].second+d[1];
            if(!index.count(make_pair(x,y))){
                result[i] = make_pair(x,y);
                q.push_back(State(a[i].first,a[i].second,x,y,1));
                v[i]=true;
                break;
            }
        }
    }

    while(!q.empty()){
        State s = q.front();q.pop_front();
        for(auto d:dirs){
            int x = s.x+d[0];
            int y = s.y+d[1];
            auto point = make_pair(x,y);
            if(index.count(make_pair(x,y))&&!v[index[point]]){
                q.push_back(State(x,y,s.ax,s.ay,s.d+1));
                result[index[point]] = make_pair(s.ax,s.ay);
                v[index[point]] = true;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<result[i].first<<" "<<result[i].second<<"\n";
    }




}