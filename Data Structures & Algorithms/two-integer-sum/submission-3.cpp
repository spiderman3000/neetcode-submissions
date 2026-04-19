class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(mp.find(target-x) != mp.end() && mp[target-x] != i){
                return {i, mp[target-x]};
            }
        }

        return {};
    }
};
