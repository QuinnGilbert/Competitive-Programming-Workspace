#include <bits/stdc++.h>

using namespace std;

int main(){

    int min = INT_MAX;
    vector<int> a;
    set<int> b;
    int terms = 10000;
    for(int i=1;i<=terms;i++){
        int x = i*(3*i-1)/2;
        a.push_back(x);
        b.insert(x);
        // cout<<x<<endl;
    }

    for(int i=0;i<terms;i++){
        for(int j=0;j<i;j++){
            // if(a[i]==70&&a[j]==22){
            //     cout<<b.count(a[i]+a[j])<<" "<<b.count(a[i]-a[j])<<endl;
            // }
            if(b.count(a[i]+a[j])&&b.count(a[i]-a[j])&&a[i]-a[j]<min){
                min = a[i]-a[j];
                cout<<j<<" "<<i<<endl;

            }
        }
    }
    cout<<min<<endl;
}

//1, 5, 12, 22, 35, 51, 70, 92, 117, 145
//4 7 10 13 16

//n+1/2=(3n-1)/2=2n-1