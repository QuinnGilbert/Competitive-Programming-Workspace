#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[i] = a[i]-b[i];
    }
    a.insert(a.begin(),1,0);
    a.push_back(0);
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    n=a.size();
    long long prev = 0;
    long long m = max(a[1],(long long)0);
    long long count=0;
    bool up = false;
    if(a[1]>0)up=true;
    for(int i=2;i<n;i++){
        if(a[i]<=0){
            count+=m-prev;
            prev=0;
            up = false;
            m=0;
        }else if(a[i-1]<a[i]&&!up){
            up=true;
        }else if(a[i-1]<a[i]){
            count+=m-prev;
            prev = a[i-1];
            // up = false;
            m=prev;
        }
        m = max(m,a[i]);
        // cout<<i<<" "<<a[i]<<" "<<count<<endl;
    }
    prev = 0;
    a[1]*=-1;
    m = max(a[1],(long long)0);
    up = false;
    if(a[1]>0)up=true;
    for(int i=2;i<n;i++){
        a[i]*=-1;
        if(a[i]<=0){
            count+=m-prev;
            prev=0;
            up = false;
            m=0;
        }else if(a[i-1]<a[i]&&!up){
            up=true;
        }else if(a[i-1]<a[i]){
            count+=m-prev;
            prev = a[i-1];
            // up = false;
            m=prev;
        }
        m = max(m,a[i]);
    }
    cout<<count<<endl;
}

//1 5 3 3 4
//1 2 2 2 1

//0 3 1 1 3
//3+2

//0 5 2 1 2 5 2 0 = 1
/*
8
0 5 2 1 2 5 2 0
0 0 0 0 0 0 0 0
*/
//04101410 +2
//03000300 +3*2
//02000200
//01000100
//00000000

//05212520
//5
//4

//0 5 2 -1 -3 -4 1 -1 3 4 0
//0 5 2 0 0 0 1 0 3 4 0
//0 0 0 1 3 4 0 1 0 0 0 

//7 4 10 4
//3 0 6 +3+6

//(unproven) You should handle negative and positive values separetely

/*
5
10 1 1 1 10
0 0 0 0 0
*/