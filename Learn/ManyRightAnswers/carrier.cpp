#include <bits/stdc++.h>

using namespace std;

int main(){

    int d;
    cin>>d;
    for(int c=0;c<d;c++){

        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long low = 0;
        long long high = 100'000'000'000'001;
        while(low!=high-1){
            long long mid = (low+high)/2;
            int count = 1;
            int sum = 0;
            for(int i=0;i<n;i++){
                if(sum+a[i]<=mid){
                    sum+=a[i];
                }else{
                    sum=a[i];
                    count++;
                }
            }
            if(count<=k){
                high = mid;
            }else{
                low = mid;
            }
        }
        int count=1;
        int sum=0;
        int result=0;
        for(int i=0;i<n;i++){
            if(sum+a[i]<=high){
                sum+=a[i];
                result++;
            }else{
                sum=a[i];
                count++;
                cout<<result<<endl;
                result=1;
            } 
        }
        cout<<result<<endl;
        for(int i=count;i<k;i++){
            cout<<0<<endl;
        }
    }

}