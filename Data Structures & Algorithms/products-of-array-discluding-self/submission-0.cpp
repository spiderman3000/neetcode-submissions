class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
       for(int i=1;i<n;i++){
        res[i] = res[i-1]*nums[i-1];
       } 
       int temp = 1;
       for(int i=n-2;i>=0;i--){
        temp = temp*nums[i+1];
        res[i] *= temp;
       }
        return res;
    }
};
