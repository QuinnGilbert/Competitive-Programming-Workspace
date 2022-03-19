#include <bits/stdc++.h>

using namespace std;

int main(){

    unordered_set<long long> t;
    unordered_set<long long> p;
    unordered_set<long long> h;
    int terms=1'000'000;
    for(long long i=1;i<=terms;i++){
        // t[i*(i+1)/2]=i;
        // p[i*(3*i-1)/2]=i;
        // h[(i*(2*i-1))]=i;
        t.insert(i*(i+1)/2);
        p.insert(i*(3*i-1)/2);
        h.insert(i*(2*i-1));
        // cout<<i*(i+1)/2<<" "<<i*(3*i-1)/2<<" "<<(i*(2*i-1))<<endl;
    }
    cout<<"check"<<endl;
    // for(int i=1;i<INT_MAX;i++){
    for(long long term=1;term<=terms;term++){
        int i=term*(term+1)/2;
        // cout<<i<<endl;
        if(t.count(i)&&p.count(i)&&h.count(i)){
            // cout<<i<<" "<<t[i]<<" "<<p[i]<<" "<<h[i]<<endl;
            cout<<i<<endl;
        }
        // if(i%1'000'000==0){
        //     cout<<i<<endl;
        // }
    }

}
//a*(a+1)/2 = b*(3b-1)/2 = c*(2c-1)

//a*(a+1) = b*(3b-1)
//a^2+a = 3b^2-b