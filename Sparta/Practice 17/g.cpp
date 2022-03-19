#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edge;
vector<int> child;
int cur;
int maxDepth;
vector<int> ans;

int getMax(int i,int d){
    int max=d;
    for(int j:edge[i]){
        int depth = getMax(j,d+1);
        if(depth>max){
            max=depth;
        }
    }
    return max;
}

bool maxPath(int i,int d){
    if(d==maxDepth){
        child.push_back(i);
        return true;
    }
    for(int j:edge[i]){
        if(maxPath(j,d+1)){
            child.push_back(i);
            return true;
        }
    }
    return false;
}

int count(int i){
    int result=1;
    for(int j:edge[i]){
        result+=count(j);
    }
    return result;
}

int dfsPrint(int root, int count){
    if(count<=0){
        return 0;
    }
    // cout<<"dfsprint ";
    // cout<<root+1<<" ";
    ans.push_back(root);
    bool out = count!=1;
    count--;
    for(int i:edge[root]){
        // cout<<root+1<<" ";//detect leaf and print after each call
        if(count!=0) {
            int counted = dfsPrint(i,count);
            count=counted;
            ans.push_back(root);
        }
    }
    return count;
}

void dfs(int root,int k){
    k--;
    // cout<<root+1<<" ";
    ans.push_back(root);
    // cout<<"dfs "<<root<<" "<<k<<endl;
    for(int i:edge[root]){
        if(i!=child[cur]){
            int num = count(i);
            dfsPrint(i,min(num,k-maxDepth));
            if(min(num,k-maxDepth)>0){
                k-=min(num,k-maxDepth);
                // cout<<root+1<<" ";
                ans.push_back(root);
            }
        }
    }
    if(k>maxDepth){
        cur++;
        maxDepth--;
        dfs(child[cur-1],k);
    }else{
        for(int i=cur;k>0;i++){
            // cout<<child[i]+1<<" ";
            ans.push_back(child[i]);
            k--;
        }
    }
}

int main(){

    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        edge = vector<vector<int>>(n);
        for(int i=1;i<n;i++){
            int x;cin>>x;
            x--;
            edge[x].push_back(i);
        }

        maxDepth = getMax(0,0);
        // cout<<maxDepth<<endl;
        // cout<<2*(k-1)-maxDepth<<endl;

        child = vector<int>();
        cur=1;

        if(k==1){
            cout<<"0\n1\n";
            continue;
        }

        // cout<<"CHECK"<<endl;
        maxPath(0,0);
        // cout<<"CHECK"<<endl;
        getMax(0,0);
        // cout<<"CHECK"<<endl;
        reverse(child.begin(),child.end());
        // cout<<"CHECK"<<endl;
        // for(int i:child){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<max(k,2*(k-1)-maxDepth)<<endl;
        // cout<<"CHECK2"<<endl;
        ans.clear();
        dfs(0,k);
        cout<<ans.size()-1<<endl;
        for(int i:ans){
            cout<<i+1<<" ";
        }
        cout<<endl;


    }

}