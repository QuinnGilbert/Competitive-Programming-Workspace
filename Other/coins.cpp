/*
 * Author: medbar
 * Date: 2021-09-16
 */
 
#include <cstring>
#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>
 
#define btoa(x) ((x) ? "YES" : "NO")
 
using namespace std;
 
typedef vector<int> vi;
 
vector<int> coins(100 + 10);
int M = 1000000000 + 7;
 
//int memo[1000000 + 10];
int memo[100 + 10][1000000 + 10];
 
int n;
 
/*
int ways(int t, int value) {
    if (value < 0) return 0;
    if (value == 0) return 1;
    if (memo[value] != -1) return memo[value];
    int ret = 0;
    for (int i = t; i < n; i++) {
        ret = (ret + ways(i, value - coins[i])) % M;
    }
    return memo[value] = ret;
}
*/
 
int ways(int type, int value) {
    //printf("type %d value %d\n", type, value);
    if (value == 0) return 1;
    if (value < 0 || type == n) return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ((ways(type + 1, value)) + (ways(type, value - coins[type]))) % M;
}
 
/*
int ways(int n, int t, int s) {
    if (s < 0) return 0;
    if (s == 0 || t == n) return 1;
    if (memo[s] != -1) return memo[s];
    int ret = 0;
    for (int i = t; i < n; i++) {
        ret = (ret + ways(n, i, s - coins[i])) % M;
    }
    return memo[s] = ret;
}
*/
 
long dp[1000001];
int main() {
    int s;
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    // cout << "CHECK"<<endl;
    // memset(dp,-1,sizeof dp);
    // memset(memo, -1, sizeof memo);
    // sort(coins.begin(), coins.begin() + n);
    // cout << ways(0, s) << endl;
    // cout << "CHECK 1"<<endl;
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=s;j++){
            // cout << i<<j<<endl;
            dp[j]=(dp[j]+dp[j-coins[i]])%1000000007;
        }
    }
    // cout << "CHECK 2"<<endl;
    cout << dp[s]<< endl;
    // for(int i =0;i<=s;i++){
    //     cout << dp[i] << " ";
    // }
    return 0;
}