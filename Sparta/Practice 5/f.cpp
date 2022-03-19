#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin>>s;
    int n = s.size();
    vector<int> a(50);
    for(int i=0;i<n;i++){
        a[i+20] = s[i]-'0';
    }
    n = 50;
    bool check = true;
    while(check){
        check = false;
        vector<int> b(n);
        for(int i=0;i<n;i++){
            b[i] = a[i]%2;
            if(i!=0&&a[i-1]>1){
                b[i]++;
                check=true;
            }
            if(i!=n-1&&a[i+1]>1){
                b[i]++;
                check=true;
            }
        }

        a=b;
        for(int i=0;i<n;i++){
            cout<<a[i];
        }
        cout<<endl;
        
    }

    

}

/*
int t;
    cin>>t;
    while(t-->0){
        string a,b,c;
        cin>>a>>b>>c;
        vector<long long> dp(max(max(a.size(),b.size()),c.size()));
        for(int i=0;i<n;i++){
            
        }
        

    }

there are four possibilities at each index:
a[i]<b[i]<c[i]
a[i]<b[i]=c[i]
a[i]=b[i]<c[i]
a[i]=b[i]=c[i]

calculate the number of ways for each index at first 3 possibilities, a[i] cannot be equal to b[i] if |a|>=|b| and same for b with c
multipy this sum by number of ways fourth possibility is true up to each index

*/