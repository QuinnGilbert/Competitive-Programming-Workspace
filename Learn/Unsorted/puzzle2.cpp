#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> result;

int value(vector<vector<int>> &a){
    int p=1;
    int res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res+=p*a[i][j];
            p*=9;
        }
    }
    return res;
}

void print(vector<vector<int>> &a){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int bfs(){
    unordered_set<int> visited;
    vector<vector<int>> res(3,vector<int>(3));
    int v=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=v;
            v++;
        }
    }
    res[2][2]=0;
    result[value(res)]=0;
    // print(a);
    deque<pair<vector<vector<int>>,int>> q;
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    q.push_back(make_pair(res,0));
    visited.insert(value(res));
    while(!q.empty()){
        pair<vector<vector<int>>,int> p = q.front();
        vector<vector<int>> cur = p.first;
        int d = p.second;
        // cout<<d<<endl;
        result[value(cur)]=d;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<4;k++){
                    int x = dir[k][0]+i;
                    int y = dir[k][1]+j;
                    if(x<3&&x>=0&&y<3&&y>=0&&cur[x][y]==0){
                        swap(cur[i][j],cur[x][y]);
                        if(!visited.count(value(cur))){
                            q.push_back(make_pair(cur,d+1));
                            visited.insert(value(cur));
                        }
                        swap(cur[i][j],cur[x][y]);
                    }
                }
            }
        }
        q.pop_front();
    }
    return -1;

}

int main(){
    int t;
    cin>>t;
    bfs();
    // cout<<result.size()<<endl;
    for(int q=0;q<t;q++){
        vector<vector<int>> a(3,vector<int>(3));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        cout<<result[value(a)]<<endl;
    }
}

/*
3
1 2 3
4 5 6
7 8 0

1 2 3
7 0 4
8 6 5

4 2 6
3 1 5
7 0 8
*/

/*
#include <bits/stdc++.h>

using namespace std;

struct state{
    vector<vector<int>> a;
    int d;
    int x;
    int y;
    state(vector<vector<int>> A, int B, int C, int D){
        a=A;
        d=B;
        x=C;
        y=D;
    }
};

int value(vector<vector<int>> &a){
    int p=1;
    int res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res+=p*a[i][j];
            p*=9;
        }
    }
    return res;
}

void print(vector<vector<int>> &a){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int bfs(vector<vector<int>> &a){
    unordered_set<int> visited;
    vector<vector<int>> res(3,vector<int>(3));
    int v=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=v;
            v++;
        }
    }
    res[2][2]=0;
    int end = value(a);
    // print(a);
    deque<state> q;
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    q.push_back(state(res,0,2,2));
    while(!q.empty()){
        state p = q.front();
        vector<vector<int>> cur = p.a;
        int d = p.d;
        // cout<<d<<endl;
        if(value(cur)==end) return d;
        for(int i=0;i<4;i++){
            int x = p.x+dir[i][0];
            int y = p.y+dir[i][1];
            if(x<3&&y<3&&x>=0&&y>=0){
                if()
            }
        }
        q.pop_front();
    }
    return -1;

}

int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        vector<vector<int>> a(3,vector<int>(3));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        cout<<bfs(a);
    }
}
*/
