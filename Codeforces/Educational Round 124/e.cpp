#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

//calc number of ways to satisfy constraints
long long calculate(int la,int lb, int ra, int rb){

    if(lb<la||rb<ra) return 0;
    return (lb-la+1)*(rb-ra+1);
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;cin>>n;
    vector<vector<int>> edge(2*n);
    for(int i=0;i<2*n;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    //calculate total number of nodes over all graphs
    long long totalNodes = 0;
    for(long long i=1;i<=n;i++){
        totalNodes+=i*(n-i+1);
    }
    // cout<<totalNodes<<endl;
    totalNodes*=n*(n+1);
    // totalNodes*=2;

    //calculate the excluded nodes
    long long count=0;
    for(int start=0;start<2*n;start++){
        int l = edge[start][0];
        int r = edge[start][1];
        bool a0 = start>=0&&start<n;

        //the requirements for both sides:
        int minA=start;//upper bound for L
        int maxA=start;//lower bound for R
        if(!a0){
            minA-=n;
            maxA-=n;
        }
        int minB=n-1;//same but for other side
        int maxB=0;//same but for other side
        bool side=1;//0 is side a, 1 is side b. We track the side that is being discluded


        int minv=min(l,r);
        int maxv=max(l,r);
        if(a0){
            minv-=n;
            maxv-=n;
        }
        //case out the first increment
        int space = maxv-1-(minv);
        int space2 = minv;
        int space3 = n-maxv-1;
        count+=calculate(0,minA,maxA,n-1)*( (space*(space+1)/2)+(space2*(space2+1)/2)+(space3*(space3+1)/2) );
        // cout<<minv<<" "<<maxv<<" "<<space3<<endl;
        // cout<<start<<": "<<calculate(0,minA,maxA,n-1)<<" "<<(space*(space+1)/2)<<" "<<(space2*(space2+1)/2)<<" "<<(space3*(space3+1)/2)<<endl;

        minB = minv;
        maxB = maxv;
        side=0;

        set<int> used;
        used.insert(start);
        used.insert(l);
        used.insert(r);

        while(true){
            int nextl=edge[l][0];
            int nextr=edge[r][0];
            if(used.count(nextl)){
                nextl=edge[l][1];
            }
            if(used.count(nextr)){
                nextr=edge[r][1];
            }
            
            int minv = min(nextl,nextr);
            int maxv = max(nextl,nextr);
            if((side==0&&!a0) || (side==1&&a0)){
                minv-=n;
                maxv-=n;
            }
            int lowerbound=-1;
            int upperbound=n;

            // cout<<"L: "<<nextl<<" R: "<<nextr<<endl;

            if(side==0){
                if(minv<minA){
                    lowerbound=minv;
                }
                if(maxv<minA){
                    lowerbound=maxv;
                }
                if(maxv>maxA){
                    upperbound=maxv;
                }
                if(minv>maxA){
                    upperbound=minv;
                }
                if(!( (minA<minv&&maxA>minv) || (minA<maxv&&maxA>maxv) )){
                    count+=calculate(lowerbound+1,minA,maxA,upperbound-1) * calculate(0,minB,maxB,n-1);
                    // cout<<minv<<" "<<maxv<<" "<<calculate(lowerbound+1,minA,maxA,upperbound-1)<<" "<<calculate(0,minB,maxB,n-1)<<endl;
                }
                // cout<<minv<<" "<<maxv<<" "<<minA<<" "<<maxA<<" "<<lowerbound<<" "<<upperbound<<endl;
                // cout<<"B: "<<minB<<" "<<maxB<<" "<<endl;
                // cout<<lowerbound+1<<" "<<minA<<" "<<maxA<<" "<<upperbound-1<<endl;
                minA=min(minA,minv);
                maxA=max(maxA,maxv);
            }else{
                if(minv<minB){
                    lowerbound=minv;
                }
                if(maxv<minB){
                    lowerbound=maxv;
                }
                if(maxv>maxB){
                    upperbound=maxv;
                }
                if(minv>maxB){
                    upperbound=minv;
                }
                if(!( (minB<minv&&maxB>minv) || (minB<maxv&&maxB>maxv) ) ){
                    count+=calculate(lowerbound+1,minB,maxB,upperbound-1) * calculate(0,minA,maxA,n-1);
                    // cout<<minv<<" "<<maxv<<" "<<calculate(lowerbound+1,minB,maxB,upperbound-1)<<" "<<calculate(0,minA,maxA,n-1)<<endl;
                }
                minB=min(minB,minv);
                maxB=max(maxB,maxv);
            }

            l=nextl;
            r=nextr;
            used.insert(l);
            used.insert(r);
            side = !side;

            if(nextl==nextr){
                break;
            }

        }

        // cout<<start<<": "<<count<<endl;
    }

    // cout<<totalNodes<<" "<<count<<endl;

    cout<<(totalNodes-count)/2<<endl;

}

/*

-On one side, you are only bounded by the restriction that the left bound must be at or below the highest and right at or above the lowest (is just l*r)
-On the other side, you are bounded by the restriction above and also the fact that the left bound must be above a certain value
    and the right bound must below a certain value

2250
1622
314

1050
422

*/