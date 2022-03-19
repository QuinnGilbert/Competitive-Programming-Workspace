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
    int curCase=0;
    while(t--){
        curCase++;
        int n,q;
        cin>>n>>q;

        vector<pair<vector<int>,int>> trie; //stores index of children and count of terminal children below
        vector<bool> end;
        trie.emplace_back(vector<int>(26,-1),n);
        end.push_back(false);
        int nextIndex=1;

        for(int i=0;i<n;i++){
            string s;cin>>s;
            int index = 0;
            for(char i:s){
                auto &cur = trie[index].first[i-'a'];
                if(cur==-1){
                    index = cur = nextIndex++;
                    trie.emplace_back(vector<int>(26,-1),0);
                    end.push_back(false);
                    trie[index].second++;
                }else{
                    index = cur;
                    trie[index].second++;
                }
            }
            end[index]=true;
        }

        vector<int> a(26);
        for(int i=0;i<26;i++){
            a[i]=i;
        }
        cout<<"Gift Exchange #"<<curCase<<":\n";
        while(q--){
            int type;
            cin>>type;

            if(type==1){
                char x,y;
                cin>>x>>y;
                int xi=0;
                int yi=0;
                for(int i=0;i<26;i++){
                    if(a[i]==x-'a')xi=i;
                    if(a[i]==y-'a')yi=i;
                }
                // cout<<xi<<" "<<yi<<endl;
                swap(a[xi],a[yi]);
                // for(int i=0;i<26;i++){
                //     cout<<a[i]<<" ";
                // }
                // cout<<endl;
            }

            if(type==2){
                int x;cin>>x;
                int index=0;
                string result="";
                int count=0;
                bool cont=true;
                while(cont){
                    // cout<<index<<endl;
                    int next=-1;
                    for(int i:a){
                        if(trie[index].first[i]!=-1) count+=trie[trie[index].first[i]].second;
                        // cout<<count<<" ";
                        if(count>=x){
                            count+=end[trie[index].first[i]];
                            count-=trie[trie[index].first[i]].second;
                            if(count==x&&end[trie[index].first[i]]){
                                result+=(char)(i+'a');
                                cont=false;
                                break;
                            }
                            next=trie[index].first[i];
                            result+=(char)(i+'a');
                            break;
                        }
                    }
                    index=next;
                    // cout<<index<<" ";
                }
                cout<<result<<"\n";
            }


        }
        cout<<"\n";
    }

}

/*

aab
aabaa
aa

*/