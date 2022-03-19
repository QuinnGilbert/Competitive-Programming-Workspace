#include <bits/stdc++.h>

using namespace std;

int main(){

    long long x,y;
    cin>>x>>y;
    cout<<bitset<64>(x)<<endl;
    string s = bitset<64>(y).to_string();
    cout<<s<<endl;

}

/*

1111
0100

100010
10001

1010001
1000101

adding a zero is just freely reversing the number
you can only add 1 to either side and reverse the number
(or remove preceeding zeroes)

can add 1s to the left freely, but can't 

*/