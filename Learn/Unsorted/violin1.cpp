#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin >> n;
        vector<bool> a(5);
        int count=0;
        int max = 0;
        a[0] = true;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x>max){
                max = x;
                count++;
                a[x] = true;
            }else if(x<max){
                for(int j=x+1;j<=max;j++){
                    if(a[j]){
                        count++;
                        a[j] = false;
                    }
                }
                if(!a[x]){
                    a[x] = true;
                    count++;
                }
                max = x;
            }
            // cout << count << endl;
        }
        cout << count << endl;
    }
}