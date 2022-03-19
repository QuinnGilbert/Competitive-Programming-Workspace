#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    

    int t;
    cin>>t;
    while(t-->0){

        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long gcd1=a[0];
        long long gcd2=a[1];
        for(int i=0;i<n;i++){
            if(i%2==0){
                gcd1=gcd(gcd1,a[i]);
            }else{
                gcd2=gcd(gcd2,a[i]);
            }
        }
        bool check1=true;
        bool check2=true;
        for(int i=0;i<n;i++){
            if(i%2==0&&a[i]%gcd2==0){
                check2=false;
            }
            if(i%2==1&&a[i]%gcd1==0){
                check1=false;
            }
        }
        if(check1){
            cout<<gcd1<<endl;
        }else if(check2){
            cout<<gcd2<<endl;
        }else{
            cout<<0<<endl;
        }
    }

}


/*

1 2 3 4 5

10 5 15

100 10 200

9 8 2 6 2 8 6 5 4

gcd(every other value) must not divide anything else
if gcd divides that value, anything less will also, so it's either the gcd or nothing


*/