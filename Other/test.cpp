#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(map.find(target-nums[i])!=map.end()){
            return {i, map[target-nums[i]] };
        }
        map.insert({nums[i],i});
    }
    return {0,0};
}

int main(){
    vector<vector<int>> dp(1000,vector<int>(1000));
    cout << dp[999][999] << endl;
}