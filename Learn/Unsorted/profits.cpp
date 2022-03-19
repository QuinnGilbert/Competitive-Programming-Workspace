#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n==0)break;
        vector<int> a(n);
        int ma = INT_MIN;
        for(int i=0;i<n;i++){
            cin >> a[i];
            ma = max(ma,a[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            ma = max(ma,sum);
            if(sum<0){
                sum = 0;
            }
        }
        cout << ma << endl;
    }
}