#include <bits/stdc++.h>

using namespace std;

bool equal(int x,int y){
    return x==0||y==0||x==y;
}

bool check(int a,int b,int c,int d){
    if(a==0&&b==0&&c==0&&d==0) return false;
    return equal(a,b)&&equal(a,c)&&equal(a,d)&&equal(b,c)&&equal(b,d)&&equal(c,d);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    deque<pair<int,int>> q;
    vector<vector<bool>> v(n,vector<bool>(m));
    vector<tuple<int,int,int>> result;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(check(a[i][j],a[i+1][j],a[i][j+1],a[i+1][j+1])){
                q.emplace_back(i,j);
                v[i][j] = true;
                result.emplace_back(i+1,j+1,max(max(a[i][j],a[i+1][j]),max(a[i][j+1],a[i+1][j+1])));
            }
        }
    }
    int count=0;
    while(!q.empty()){
        count++;
        auto[x,y] = q.back();
        q.pop_back();
        // cout<<x<<" "<<y<<endl;

        a[x][y]=0;
        a[x+1][y]=0;
        a[x][y+1]=0;
        a[x+1][y+1]=0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        for(auto d:dir){
            int i=x+d[0];
            int j=y+d[1];
            if(i<n-1&&j<m-1&&i>=0&&j>=0&&!v[i][j]&&check(a[i][j],a[i+1][j],a[i][j+1],a[i+1][j+1])){
                q.emplace_back(i,j);
                v[i][j] = true;
                result.emplace_back(i+1,j+1,max(max(a[i][j],a[i+1][j]),max(a[i][j+1],a[i+1][j+1])));
            }
        }
    }
    if(count!=(n-1)*(m-1)){
        cout<<-1<<"\n";
    }else{
        cout<<result.size()<<"\n";
        for(int j=result.size()-1;j>=0;j--){
            auto i = result[j];
            cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<"\n";
        }
    }
}