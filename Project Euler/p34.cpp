#include <bits/stdc++.h>

using namespace std;

int factorial(int a){
    int result=1;
    for(int i=1;i<=a;i++){
        result*=i;
    }
    return result;
}

int main(){

    int result=0;
    for(int i=3;i<1'000'000'000;i++){
        string s = to_string(i);
        int sum=0;
        for(char i:s){
            sum+=factorial(i-'0');
        }
        if(sum==i){
            result+=i;
        }
        if(i%10'000'000==0)cout<<result<<endl;
    }
    cout<<result<<endl;

}