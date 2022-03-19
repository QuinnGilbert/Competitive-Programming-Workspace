#include <bits/stdc++.h>

using namespace std;

int go(vector<int> &x, vector<int> &y, int index, int n, int days, int d){
    if(days>d) return 0;
    if(index==n)return 0;
    return max((days+x[index]>d? 0:go(x,y,index+1,n,days+x[index],d)+y[index]),go(x,y,index+1,n,days,d));
}

int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n,d;
        cin>>n>>d;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        int res = go(x,y,0,n,0,d);
        cout<<res<<endl;
    }
    return 0;
}