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
        int n,d;cin>>n>>d;

        int min=INT_MAX;
        vector<int> a(n);
        int prev=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]-prev-1<min) min = a[i]-prev-1;
            prev=a[i];
        }

        auto move = [&](int index)->int{
            int max=-1;
            int maxi=0;
            prev=0;
            for(int i=0;i<n;i++){
                if(i!=index){
                    int gap = a[i]-prev-1;
                    if((gap-1)/2>max){
                        max=(gap-1)/2;
                        maxi=a[i]-((gap-1)/2+1);
                    }
                    prev = a[i];
                }
            }
            if(d-prev-1>max){
                max=d-prev;
                maxi=d;
            }
            // cout<<"maxi: "<<maxi<<endl;
        
            vector<int> b;
            for(int i=0;i<n;i++){
                if(i!=index){
                    b.push_back(a[i]);
                }
            }
            b.push_back(maxi);
            sort(b.begin(),b.end());
            min=INT_MAX;
            prev=0;
            for(int i=0;i<n;i++){
                int gap = b[i]-prev-1;
                if(gap<min) min = gap;
                prev=b[i];
            }
            return min;
        };

        set<int> p;
        prev=0;
        for(int i=0;i<n;i++){
            if(a[i]-prev-1==min){
                p.insert(i);
                p.insert(i-1);
            }
            prev=a[i];
        }

        if(p.size()>3){
            // cout<<"1 ";
            cout<<min<<endl;
        }else{
            vector<int> v;
            for(int i:p){
                v.push_back(i);
            }
            sort(v.begin(),v.end());

            if(p.size()==3){
                // cout<<"2 ";
                cout<<move(v[1])<<endl;
            }else{
                if(v[0]==-1){
                    // cout<<"3 ";
                    cout<<move(v[1])<<endl;
                }else{
                    // cout<<"4 ";
                    cout<<max(move(v[1]),move(v[0]))<<endl;
                }
            }
        }
    }

}

/*

for the minimum gap, must move either the one on the right or left 
EDGE CASE for when you move the first value?

if there are 2 minimum gaps that are not adjacent the minimum can't change
if there are more than 2 minimum gaps, the answer can't ever be changed

5 15
3 6 9 12 15

1 5
1 2 3 4 5
0 1 0 0 1


*/