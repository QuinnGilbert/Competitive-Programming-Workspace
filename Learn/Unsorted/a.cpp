#include <bits/stdc++.h>

using namespace std;

int main(){
    // cout << LONG_LONG_MAX <<endl;
    // cout << INT_MAX<<endl;
    int t;
    cin >> t;
    for(int q=0;q<t;q++){
        int n;
        cin >> n;
        priority_queue<long long> queue;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            queue.push(-x);
        }
        long long sum = 0;
        for(int i=0;i<n-1;i++){
            long long a = -queue.top();
            queue.pop();
            long long  b = -queue.top();
            queue.pop();
            sum+=a+b;
            // cout << a<<" " <<b << endl;
            queue.push(-(a+b));
        }
        cout << sum << endl;
    }
}