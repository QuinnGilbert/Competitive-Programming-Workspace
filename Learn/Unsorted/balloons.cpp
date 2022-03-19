#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n,a,b;
        cin >>n>>a>>b;
        if(n==0&&a==0&&b==0)break;
        vector<int> t(n);
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0;i<n;i++){
            cin>>t[i]>>x[i]>>y[i];
        }
        vector<bool> used(n);
        
        long res=0;
        for(int j=0;j<n;j++){
            int max=-1;
            int index=0;
            int type=0;
            for(int i=0;i<n;i++){
                if(!used[i]){
                    // cout << i << endl;
                    int diff = abs(x[i]-y[i]);
                    if(diff>max){
                        max=diff;
                        index=i;
                        if(x[i]<y[i]){
                            type = 0;
                        }else{
                            type = 1;
                        }
                    }
                }
            }

            if(type==0){
                if(t[index]<=a){
                    res+=t[index]*x[index];
                    a-=t[index];
                }else{
                    res+=a*x[index];
                    res+=(t[index]-a)*y[index];
                    b-=(t[index]-a);
                    a=0;
                }
            }else{
                if(t[index]<b){
                    b-=t[index];
                    res+=t[index]*y[index];
                }else{
                    res+=b*y[index];
                    res+=(t[index]-b)*x[index];
                    a-=(t[index]-b);
                    b=0;
                }
            }
            // cout << res << " " << index <<  endl ;
            used[index]=true;
        }
        cout << res << endl;
    }

}
/*
4 15 25
10 0 20
10 10 20
10 15 20
10 20 10
*/