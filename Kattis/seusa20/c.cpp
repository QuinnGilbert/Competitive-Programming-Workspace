#include <bits/stdc++.h>

using namespace std;

vector<int> tree;
int length = 1;

void update(int i, int v){
    int index=i+length;
    tree[index]=v;
    while(index!=0){
        index/=2;
        tree[index] = tree[index*2]+tree[index*2+1];
    }
}

int query(int l, int r){
    l+=length;
    r+=length;
    int result = 0;
    while(l<=r){
        // cout<<"query: "<<l<<" "<<r<<" "<<result<<endl;
        if(l%2==1){
            result+=tree[l];
            l++;
        }
        if(r%2==0){
            result+=tree[r];
            r--;
        }
        l/=2;
        r/=2;
    }
    return result;
}

int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    vector<pair<int,int>> sorted(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sorted[i]=make_pair(a[i],i);
    }
    //compress input
    sort(sorted.begin(),sorted.end());
    for(int i=0;i<n;i++){
        a[sorted[i].second]=i;
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    //initialize segment tree
    while(length<n){
        length*=2;
    }
    tree.resize(length*2);

    fill(tree.begin(),tree.end(),0);
    vector<int> left(n);
    for(int i=0;i<n;i++){
        // for(int i=0;i<tree.length();i++){
        //     cout<<tree[i]<<" ";
        // }
        // cout<<endl;
        left[i] = query(a[i],n-1);
        // cout<<a[i]<<" "<<n<<" "<<query(a[i],n)<<endl;
        update(a[i],1);
    }

    fill(tree.begin(),tree.end(),0);
    vector<int> right(n);
    for(int i=n-1;i>=0;i--){
        right[i] = query(a[i],n-1);
        update(a[i],1);
    }

    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=min(right[i],left[i]);
        // cout<<right[i]<<" "<<left[i]<<endl;
    }
    cout<<sum<<"\n";


}

/*

If you already have a sequence that is increasing, you should never move elements out of it (likewise for decreasing on the other end)
Is there any case where you would want to move the highest number? yes:
1 5 2 4 3
1 2 5 4 3

5 3 6 8 1 2 4 7

you can choose whether to put each number on either side (greedy? take it or leave it?)
you can greedily choose which side to put each smallest element and then effectively remove it from the array

*/