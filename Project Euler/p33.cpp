/*

49/98


8/9
7/9

x/y



19/95 = 1/5

49/98 = 4/8 = 1/2

16/64 = 1/4

26/65 = 2/5

(1*1*1*2)/(5*2*4*5) = 1/100


(x-d)/(y-10d) = x/y

x/y x<y

x+d/y+10d
x+10d/y+d

solve for integer pairs x,y



24/32 = 4/3





*/
#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(b%a==0){
        return a;
    }
    return gcd(b%a,a);
}

int main(){

    cout<<gcd(100,30)<<endl;

    for(int i=2;i<9;i++){
        for(int j=1;j<i;j++){
            for(int k=1;k<=9;k++){
                // int x = gcd(j+k,i+10*k);
                // if(x!=1&&j+k>10&&i+10*k>10)cout<<j+k<<"/"<<i+10*k<<" "<<(j+k)/x<<"/"<<(i+10*k)/x<<endl;
                
                // int x = gcd(j+10*k,i+k);
                // if(x!=1&&j+k*10>10&&i+k>10)cout<<j+k*10<<"/"<<i*10+k<<" "<<(j+k*10)/x<<"/"<<(i+k)/x<<endl;
                int x = j*10+k;
                int y = i+k*10;
                int g = gcd(x,y);
                if(g!=1&&x/g<10&&y/g<10)cout<<x<<"/"<<y<<" "<<x/g<<"/"<<y/g<<endl;
            }
        }
    }

}