class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        // monotonic decreasing queue
        for(int i=0;i<nums.size();i++){
            int num = nums[i];

            // descending order
            while(!dq.empty() && dq.back() < num){
                dq.pop_back();
            }
            dq.push_back(num);

            // slide the window
            if(i >= k && dq.front() == nums[i-k]){
                dq.pop_front();
            }

            if(i >= k-1){
                res.push_back(dq.front());
            }
        }

        return res;
    }
};