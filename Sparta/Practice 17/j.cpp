#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s;cin>>s;
    int n = s.size();

    //if none filled print 0
    bool check=true;
    for(char i:s){
        if(i=='#') check = false;
    }
    if(check){
        cout<<0<<endl;
        return 0;
    }

    //find first character which sets guideline
    int start=0;
    int end=0;
    int size = 0;
    for(int i=0;i<n;i++){

    }




}

/*

The first value is equal to the index of the last filled square in the first block

from the right: sum of values + number of values = index of first filled square

a[0] = 3
remaining = 6-3 = 3

1110111011100
0011101110111
0010001000100
0000000000000
3 3 3

##__##__##
______##__


01
011
0101
01101
011011
0101011
*/