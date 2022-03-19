#include <bits/stdc++.h>

using namespace std;

int MAX = 1000000;

int main(){
    int n;
    cin >> n;
    vector<int> a(MAX+1);
    int x = 1;
    while(x*x<=MAX){
        a[x*x]++;
        x++;
    }
    for(int i=1;i<=MAX;i++){
        a[i]+=a[i-1];
    }

    for(int i=0;i<n;i++){
        int s,e;
        cin >> s >> e;
        cout << (e-s+1)-(a[e]-a[s-1]) << endl;
    }
}