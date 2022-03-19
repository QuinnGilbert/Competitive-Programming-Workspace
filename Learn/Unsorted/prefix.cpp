#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int res = x;
        if(x==1){
            cout<<"1: 1"<<endl;
            continue;
        }
        vector<long long> a(1000);
        a[0]=1;
        int index=0;
        long long total=0;
        x--;
        // cout<<"CHECK";
        while(x>0){
            cout<<a[index]<<" "<<a[index]*index<<endl;
            
            if(a[index]<=x){
                a[index+4]+=a[index];
                a[index+1]+=a[index];
                total+=a[index]*(index+1);
                total+=a[index]*(index+4);
                total-=a[index]*(index);
                x-=a[index];
                index++;x
            }else{
                total+=x*(index+1);
                total+=x*(index+4);
                total-=x*(index);
                x=0;
            }
        }
        // cout<<index<<endl;
        cout<<res<<": "<<total<<endl;
    }
}
//same idea as before, but you can add multiple at a time