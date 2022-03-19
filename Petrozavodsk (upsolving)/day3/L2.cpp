#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = int(2e9);

template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
    cout << "[";
    for(auto &x : vec) os << x << " ";
    os << "]";
    return os;
}

template<class PA, class PB> ostream& operator<<(ostream &os, const pair<PA, PB>& p) {
    return os << "<" << p.first << "," << p.second << ">";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,q;
    cin>>n>>q;
    vector<vector<pair<int,int>>> edge(n);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;

        edge[a].emplace_back(b,1);
        edge[b].emplace_back(a,-1);
    }

    int maxGCD = -1;
    vector<int> dist(n);
    vector<bool> outerv(n);
    for(int i=0;i<n&&maxGCD!=1;i++){
        if(outerv[i]) continue;
        vector<bool> v(n);
        vector<int> used;
        deque<pair<int,int>> queue;
        queue.push_back(make_pair(i,0));
        // cout<<i<<endl;
        while(!queue.empty()&&maxGCD!=1){
            int index = queue.front().first;
            int d = queue.front().second;
            // cout<<index<<" "<<d<<endl;
            queue.pop_front();
            used.push_back(index);
            for(auto [j,w] : edge[index]){
                assert(!outerv[j]);
                if(!v[j]){
                    v[j] = true;
                    queue.emplace_back(j,d+w);
                    dist[j]=d+w;
                    // cout<<"Check1 "<<j<<endl;
                }else{
                    if(abs(d+w-dist[j])==0){
                        continue;
                    }
                    // cout<<"Check2 "<<maxGCD<<endl;
                    // cout<<j<<" "<<dist[j]<<" "<<d+w<<endl;
                    if(maxGCD==-1){
                        // cout<<"Check3"<<endl;
                        maxGCD = abs(dist[j]-(d+w));
                    }
                    else if((abs(d+w-dist[j]))%maxGCD!=0){
                        maxGCD = gcd(maxGCD,(abs(d+w-dist[j]))%maxGCD);
                        if(maxGCD==1){
                            break;
                        }
                        v = vector(n,false);
                        used.clear();
                        // queue.clear();
                        queue.emplace_back(j,0);
                    }
                }

            }
        }

        for(int j:used){
            outerv[j] = true;
        }

    }

    // cout<<"GCD="<<maxGCD<<endl;

    if(maxGCD==-1){
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }else{
        vector<int> result;
        for(int i=1;i*i<=maxGCD;i++){
            if(maxGCD%i==0){
                if(i*i==maxGCD){
                    result.push_back(i);
                }else{
                    result.push_back(i);
                    result.push_back(maxGCD/i);
                }
            }
        }
        cout<<result.size()<<endl;
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }

}