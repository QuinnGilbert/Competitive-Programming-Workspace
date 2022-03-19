#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> place(n+1);
    vector<vector<int>> add(n+1);
    vector<vector<int>> rem(n+1);

    // set<int> tree;
    // tree.insert(-1);
    set<int> less;
    set<int> greater;
    less.insert(INT_MAX);
    greater.insert(INT_MAX);
    for(int i=0;i<n;i++){
        cin>>a[i];
        place[a[i]]=i;
        if(*less.upper_bound(-a[i])==INT_MAX){
            add[0].push_back(i);
        }else{
            // cout<<i<<" "<<*tree.upper_bound(a[i])<<endl;
            add[-*less.upper_bound(-a[i])].push_back(i);
        }
        if(*greater.upper_bound(a[i])==INT_MAX){
            // rem[0].push_back(i);
        }else{
            rem[*greater.lower_bound(a[i])].push_back(i);
        }
        // tree.insert(a[i]);
        less.insert(-a[i]);
        greater.insert(a[i]);
    }

    // for(int i=0;i<=n;i++){
    //     cout<<"[";
    //     for(int x:add[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<"]";
    // }
    // cout<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<"[";
    //     for(int x:rem[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<"]";
    // }
    // cout<<endl;

    vector<int> linked(n);
    less.clear();
    greater.clear();
    less.insert(INT_MAX);
    greater.insert(INT_MAX);
    int count=0;
    for(int i=0;i<=n;i++){
        for(int x:add[i]) {
            int prev=-1;
            int next=-1;
            if(*less.upper_bound(-x)!=INT_MAX) {
                prev=-*less.upper_bound(-x);
            }
            if(*greater.upper_bound(x)!=INT_MAX) {
                next=*greater.upper_bound(x);
            }
            if( (prev==-1||linked[prev]!=2) && (next!=-1&&linked[next]==1) ) {
                count++;
            }
            linked[x]=2;
            less.insert(-x);
            greater.insert(x);
        }
        for(int x:rem[i]) {
            int prev=-1;
            int next=-1;
            if(*less.upper_bound(-x)!=INT_MAX) {
                prev=-*less.upper_bound(-x);
            }
            if(*greater.upper_bound(x)!=INT_MAX) {
                next=*greater.upper_bound(x);
            }
            if( (prev!=-1&&linked[prev]==2) && (next==-1||linked[next]!=1) ) {
                count--;
            }
            linked[x]=0;
            less.erase(-x);
            greater.erase(x);
        }
        if(i!=0) {
            int prev=-1;
            int next=-1;
            if(*less.upper_bound(-place[i])!=INT_MAX) {
                prev=-*less.upper_bound(-place[i]);
            }
            if(*greater.upper_bound(place[i])!=INT_MAX) {
                next=*greater.upper_bound(place[i]);
            }
//				System.out.println(place[i]+" "+prev+" "+next);
            if( (prev!=-1&&linked[prev]==2) && (next==-1||linked[next]!=1) ) {
                count++;
            }
            if( (prev==-1||linked[prev]!=2) && (next!=-1&&linked[next]==1) ) {
                count--;
            }
            linked[place[i]]=1;
        }
        
        // for(int i:linked){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        cout<<count<<"\n";
    }
}

/*

we are counting the number of times that we identify an upper and lower bound (in that order) that is tighter than the previous
(pretty much counting the number of changes/2 after first high)

we can preprocess the array to add only to the sections that would contain a hi-lo (now we need to know how to figure that out)

going from x to x+1, the only change is that x+1 goes from a high to a low 
when that happens subsequent lows<x+1 are removed and highs>x+1 are added (up to the next point?)
each index always goes blank->high->low




*/