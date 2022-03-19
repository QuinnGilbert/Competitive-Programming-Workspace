#include <bits/stdc++.h>

using namespace std;

int main(){

    int max=0;
    for(int p=1;p<=1000;p++){
        int count=0;
        for(int a=1;a<p;a++){
            for(int b=1;a+b<p;b++){
                double c = sqrt(a*a+b*b);
                if(a+b+c==p)count++;
            }
        }
        if(count>max){
            max=count;
            cout<<p<<" "<<max<<endl;
        }
    }

}