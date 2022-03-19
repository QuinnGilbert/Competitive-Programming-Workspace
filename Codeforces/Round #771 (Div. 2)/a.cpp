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

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        int index=0;
        while(index<n&&a[index]==index+1){
            index++;
        }
        if(index!=n){
            int left = index;
            int right=0;
            for(int i=0;i<n;i++){
                if(a[i]==index+1){
                    right = i;
                }
            }
            // cout<<left<<" "<<right<<endl;
            // for(int i=0;i<(right-left)/2;i++){
            //     swap(a[i+left],a[right-i-1]);
            // }
            reverse(a.begin()+left,a.begin()+right+1);
        }
        // cout<<"CHECK"<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

}