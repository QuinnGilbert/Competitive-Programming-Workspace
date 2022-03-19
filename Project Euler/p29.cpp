#include <bits/stdc++.h>

using namespace std;

bool test(int x, int p){
    int result=1;
    for(int i=0;i<p;i++){
        result*=x;
        if(result>100)return false;
    }
    return true;
}

int main(){

    int dup=0;
    int count=0;
    int total=0;
    vector<bool> used(101);
    for(int i=2;i<=100;i++){
        // if(used[i])continue;
        for(int pow=2;pow<=100;pow++){
            // int x=pow;
            // int y=i;
            // int count=0;
            // while(x%2==0&&x!=2&&y*i<=100){
            //     count++;
            //     x/=2;
            //     y*=i;
            //     used[y]=true;
            // }
            // //cout<<i<<" "<<pow<<" "<<count<<endl;
            // dup+=count;
            // int x=pow;
            // int y=i;
            bool check = false;
            for(int j=2;j<=pow;j++){
                if(pow%j==0&&pow!=j&&test(i,j)){
                    check=true;
                }
            }
            if(!check)count++;
            else cout<<i<<" "<<pow<<endl;
        }
    }
    // cout<<99*99-dup<<endl;
    cout<<count<<endl;
    cout<<99*99-count<<endl;
    //450+32+
}

//duplicates only when powers of each number are put to half its power

//2^2 = 4^1
//2^3 = 8^1
//2^4 = 4^2 = 16^1
//2^5 = 32^1
//2^6 = 8^2 = 64^1

//2^8 = 4^4 = 16^2

//4^4 = 16^2

//3^8 = 9^4 = 81^2

//3^9 = 27^3

//3^3 = 27^1

//9*49+3*32+2*24+1*19+15

//2^12

//the next power has to be less 100
