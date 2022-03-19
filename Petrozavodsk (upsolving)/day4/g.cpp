#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    vector<int> unique = {0, 2, 3, 2, 4, 7, 9, 17, 15, 18, 7, 61, 25, 64, 85, 49};

    long long MOD = 1000000007;
    int n;
    cin>>n;
    vector<bool> result(n); //true is + false is x
    int m = n+1;

    if(n<16){
        cout<<"?";
        for(int i=0;i<m;i++){
            cout<<" "<<unique[i];
        }

        cout<<endl<<flush;
        
        int answer;
        cin>>answer;
        for(int i=0;i<pow(2,n);i++){
            int x = i;
            bool check = true;
            long long sum=0;
            for(int j=0;j<n;j++){
                // cout<<x<<endl;
                // if(i==163)cout<<x<<endl;
                if(x%2==1){
                    result[j]=1;
                    sum = (sum+unique[j+1])%MOD;
                }else{
                    result[j]=0;
                    sum = (sum*unique[j+1])%MOD;
                }
                x/=2;
                // if(i==163)cout<<"sum="<<sum<<endl;
            }
            if(i==pow(2,n)-1){
                assert(answer==sum);
            }
            if(answer==sum){
                break;
            }
        }
        cout<<"! ";
        for(int i=0;i<n;i++){
            if(result[i]){
                cout<<"+";
            }else{
                cout<<"x";
            }
        }
        cout<<endl<<flush;
        return 0;
    }

    int start = m-16;
    while(true){
        cout<<"?";
        for(int i=0;i<start;i++){
            cout<<" 0";
        }
        for(int i=0;i<16;i++){
            cout<<" "<<unique[i];
        }
        for(int i=start+16;i<m;i++){
            if(result[i-1]){
                cout<<" 0";
            }else{
                cout<<" 1";
            }
        }
        cout<<endl<<flush;
        
        int answer;
        cin>>answer;
        for(int i=0;i<pow(2,15);i++){
            int x = i;
            bool check = true;
            long long sum=0;
            for(int j=0;j<15;j++){
                if(x%2==1){
                    result[start+j]=1;
                    sum = (sum+unique[j+1])%MOD;
                }else{
                    result[start+j]=0;
                    sum = (sum*unique[j+1])%MOD;
                }
                x/=2;
            }
            // cout<<answer<<endl;
            if(i==pow(2,15)-1){
                assert(answer==sum);
            }
            if(answer==sum){
                break;
            }
        }
        if(start==0) break;
        start-=15;
        if(start<0) start = 0;
    }

    cout<<"! ";
    for(int i=0;i<n;i++){
        if(result[i]){
            cout<<"+";
        }else{
            cout<<"x";
        }
    }
    cout<<endl<<flush;

}

/*
0
2

0 xx
3 x+
6 +x
5 ++

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 3 2 4 7 9 17 15 18 7 61 25 64 85 49

*/