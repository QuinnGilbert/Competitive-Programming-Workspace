#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    int count2=0;
    int count1=0;
    int x=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b%2==0){
            a%=(b+1);
            if(a==b){
                count2++;
                x^=2;
            }else if(a%2==1){
                count1++;
                x^=1;
            }
        }else{
            if(a%2==1){
                count1++;
                x^=1;
            }
        }
    }

    if(x==0){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
    // if(count2==1){
    //     cout<<"Alice"<<endl;
    // }else{
    //     if((count1+count2)%2==1){
    //         cout<<"Alice"<<endl;
    //     }else{
    //         cout<<"Bob"<<endl;
    //     }
    // }


}