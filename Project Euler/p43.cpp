#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[] = {2,3,5,7,11,13,17};
    int count=0;
    long long sum=0;
    string s;
    while(next_permutation(a,a+10)){
        s="";
        for(int i=0;i<10;i++){
            s+=to_string(a[i]);
        }
        bool check = true;
        for(int i=0;i<7;i++){
            int x = stoi( s.substr(i+1,3) );
            if(x%b[i]!=0) check = false;
        }
        if(check){
            cout<<s<<endl;
            sum+=stoll(s);
        }
        if(count%100000==0){
            cout<<count<<" "<<s<<endl;
        }
        count++;
    }
    cout<<"check"<<endl;
    cout<<sum<<endl;

}