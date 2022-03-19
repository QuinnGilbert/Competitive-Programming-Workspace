#include <bits/stdc++.h>

using namespace std;



int main(){

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<n-2;i++){
        if(s.substr(i,3)=="abc"){
            count++;
        }
    }
    for(int i=0;i<q;i++){
        int index;
        char c;
        cin>>index>>c;
        index--;
        int before = 0;
        if(index-2>=0&&s.substr(index-2,3)=="abc")before++;
        if(index-1>=0&&index+1<n&&s.substr(index-1,3)=="abc")before++;
        if(index+2<n&&s.substr(index,3)=="abc")before++;

        s[index] = c;
        int after = 0;
        if(index-2>=0&&s.substr(index-2,3)=="abc")after++;
        if(index-1>=0&&index+1<n&&s.substr(index-1,3)=="abc")after++;
        if(index+2<n&&s.substr(index,3)=="abc")after++;
        count+=after-before;
        // cout<<s<<" "<<after<<" "<<before<<endl;
        cout<<count<<endl;
    }

}



//test if there was abc before and after, add difference

//1 2 3 1 2 3 1 2 3

//1 2 3 2 3

//1 2 3 3 3