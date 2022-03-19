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

101 = 020 
all states with only ones and zeroes are equal to the sequences that create them

Processing a single 2 on the end (maybe anywhere) will be the same as processing each 2 one at a time (leaving other 2s unchanged)

*/