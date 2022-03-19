ector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(map.contains(target-nums[i])){
            return {i,map.get(target-nums[i])};
        }
        map.insert(nums[i],i);
    }
    return {0,0};
}

int main(){
    vector<int> ans = twoSum({1,2,3,4},5);
    cout << ans[0] << " " << ans[1];
}