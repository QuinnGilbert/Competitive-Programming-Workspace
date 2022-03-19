#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long count=0;
    long long left=0;
    long long right=0;
    bool first=true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='G'){
            right++;
        }else{
            long long x = (left+1)*(right+1)-1;
            if(left!=0)x--;
            if(right!=0)x--;
            if(first){
                first=false;
            }else{
                count+=x;
            }
            left = right;
            right = 0;
            // cout<<i<<" "<<left<<" "<<right<<" "<<count<<endl;
        }
    }
    long long x = (left+1)*(right+1)-1;
    if(left!=0)x--;
    if(right!=0)x--;
    if(!first)count+=x;
    left=0;
    right=0;
    first = true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='H'){
            right++;
        }else{
            x = (left+1)*(right+1)-1;
            if(left!=0)x--;
            if(right!=0)x--;
            if(first){
                first=false;
            }else{
                count+=x;
            }
            left = right;
            right = 0;
        }
    }
    x = (left+1)*(right+1)-1;
    if(left!=0)x--;
    if(right!=0)x--;
    if(!first)count+=x;
    cout<<count<<endl;
}

//GGGGGHGGGGGH

//GGGHGGG
//(left+1) * (right+1) - 1, -1 for each side

