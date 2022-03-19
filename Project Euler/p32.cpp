#include <bits/stdc++.h>

using namespace std;

bool test(string a,string b,string c){
    if(a.size()+b.size()+c.size()!=9){
        return false;
    }
    unordered_set<char> nums;
    for(char i:a+b+c){
        if(i!='0')nums.insert(i);
    }
    if(nums.size()==9){
        cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    }
    return nums.size()==9;
}

int main(){

    unordered_set<int> all;
    int max = 1'000'000; //can make this smaller for sure
    //1'000'000
    int count=0;
    for(int i=0;i<max;i++){
        for(int j=1;j*j<=max;j++){
            if(i%j==0){
                if(test(to_string(i),to_string(j),to_string(i/j))){
                    all.insert(i);
                }
            }
        }
    }
    cout<<all.size()<<endl;
    long long sum = 0;
    for(int i: all){
        sum+=i;
    }
    cout<<sum<<endl;
}

