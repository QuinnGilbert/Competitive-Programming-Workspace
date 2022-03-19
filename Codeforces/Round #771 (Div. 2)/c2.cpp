#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        deque<int> stack;
        vector<bool> removed(n);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            x--;
            stack.push_back(x);
        }
        int groups=0;
        for(int i=n-1;i>=0;i--){
            if(removed[i]) continue;
            int min=i;
            while(stack.back()!=i){
                removed[stack.back()]=true;
                if(stack.back()<min) min = stack.back();
                stack.pop_back();
            }
            stack.pop_back();
            if(min==i) groups++;
            stack.push_back(min);
            removed[min] = false;
        }
        cout<<groups<<endl;
    }

}