class Solution {
public:
    int findMin(vector<int> &nums) {
        int out = nums[0];
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[l] > nums[r]){
                if(nums[mid] >= nums[l]){
                     l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                return nums[l]; // just upon increasing, first topple means the lowest value is reached.
            }
        }
        return nums[r];
    }
};
