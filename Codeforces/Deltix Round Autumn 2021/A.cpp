#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long Max=0;
        for(int i=0;i<n;i++){
            vector<long long> b = a;
            for(int j=0;j<n;j++){
                if(j!=i){
                    while(b[j]%2==0){
                        b[j]/=2;
                        b[i]*=2;
                    }
                }
            }
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=b[j];
            }
            Max=max(Max,sum);
        }
        cout<<Max<<endl;
    }

}