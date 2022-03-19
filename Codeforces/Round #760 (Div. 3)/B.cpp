#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<string> a(n);
        string result="";
        bool check=false;
        for(int i=0;i<n-2;i++){
            cin>>a[i];
            if(i==0){
                result+=a[i];
            }else if(a[i-1][1]!=a[i][0]){
                result+=a[i];
                check = true;
            }else{
                result+=a[i][1];
            }
        }
        if(!check)result+="a";
        cout<<result<<endl;
    }

}

//ab bb ba aa ba
//a-b-b-a-a-b-a

//abbaaba

//ab ab ba aa
