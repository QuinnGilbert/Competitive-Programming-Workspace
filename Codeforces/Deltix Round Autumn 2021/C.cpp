#include <bits/stdc++.h>

using namespace std;


bool prime(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n,e;
        cin>>n>>e;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long count=0;
        for(int start=0;start<e;start++){
            long long behind=0;
            long long front=0;
            bool p = false;
            for(int i=start;i<n;i+=e){
                if(a[i]==1){
                    front++;
                }else{
                    if(p){
                        count+=(behind+front+1)*(behind+front+2)/2-front*(front+1)/2-behind*(behind+1)/2-1;
                    }
                    behind = front;
                    front = 0;
                    if(prime(a[i])){
                        p=true;
                    }else{
                        p=false;
                    }
                }
            }
            if(p) count+=(behind+front+1)*(behind+front+2)/2-front*(front+1)/2-behind*(behind+1)/2-1;
        }
        cout<<count<<endl;
        
    }

}

//can easily create some sequence 0 for not prime, 1 for 1, 2 for prime

//1 2 1 1 2 1 0 1 1
//1 2 1 1
//for each section that has a 2, count how many subarrays contain 2
//n*n+1 - front*front+1 - back*back+1 - 1
//10 - 1 - 3 - 1 = 5

