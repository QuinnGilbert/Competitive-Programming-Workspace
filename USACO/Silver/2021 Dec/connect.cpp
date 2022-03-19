#include <bits/stdc++.h>

using namespace std;

int min1,min2;
vector<int> group;

void dfs(int i, vector<vector<int>> &e, vector<bool> &v){
    // cout<<i<<endl;
    v[i]=true;
    group.push_back(i);
    for(int j:e[i]){
        if(!v[j])dfs(j,e,v);
    }
}

int search(vector<int> &a, int i){
    int low=0;
    int high=a.size();
    while(low<high-1){
        int mid = (low+high)/2;
        if(a[mid]>i){
            high=mid;
        }else{
            low=mid;
        }
    }
    if(low+1<a.size()){
        return min(abs(i-a[low]),abs(i-a[low+1]));
    }
    return abs(i-a[low]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> e(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        vector<bool> v(n);
        // cout<<"CHECK"<<endl;
        group.clear();
        dfs(0,e,v);
        vector<int> start = group;
        sort(start.begin(),start.end());
        group.clear();
        dfs(n-1,e,v);
        vector<int> end = group;
        sort(end.begin(),end.end());
        for(int i=0;i<n;i++) v[i] = false;
        long long result = LONG_LONG_MAX;
        for(int i=0;i<n;i++){
            if(!v[i]){
                min1 = INT_MAX;
                min2 = INT_MAX;
                group.clear();
                dfs(i,e,v);
                //binary search for the value closest to each value in group
                long long mins = INT_MAX;
                long long mine = INT_MAX;
                for(int j:group){
                    long long diff1 = search(start,j);
                    long long diff2 = search(end,j);
                    mins=min(mins,diff1);
                    mine=min(mine,diff2);
                }
                // if(mins==0){
                //     result = min(result,(mine/2)*(mine/2) + ((mine+1)/2)*((mine+1)/2) );
                // }else if(mine==0){
                //     result = min(result,(mins/2)*(mins/2) + ((mins+1)/2)*((mins+1)/2) );
                // }else{
                //     result=min(result,mins*mins+mine*mine);
                // }
                result=min(result,mins*mins+mine*mine);
                // cout<<i<<" "<<mins<<" "<<mine<<"\n";
            }
        }
        cout<<result<<"\n";
    }

}

/*

put graph into groups of connected components
binary search for the closest element to the first and last component

2
6 2
1 2
5 6
5 3
1 2
2 3
4 5

*/