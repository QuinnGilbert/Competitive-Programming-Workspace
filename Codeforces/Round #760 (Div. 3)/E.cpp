#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> a(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        long long x = n*(n+1)/2;
        if(sum%x!=0){
            cout<<"NO"<<endl;
            continue;
        }
        sum/=x;
        vector<long long> result(n);
        bool check = true;
        for(int i=0;i<n;i++){
            // cout<<(sum-(a[i]-a[(i-1+n)%n]))%n<<endl;
            if((sum-(a[i]-a[(i-1+n)%n]))%n!=0||(sum-(a[i]-a[(i-1+n)%n]))<=0){
                check = false;
                break;
            }
            result[i]=(sum-(a[i]-a[(i-1+n)%n]))/n;
        }
        if(!check){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }

}

/*
1 4 3 2
2 1 4 3
3 2 1 4
4 3 2 1

b[1]-b[0]=a[0]+a[2]+a[3]-a[1]*(n-1)
= sum-a[i]*n
*/