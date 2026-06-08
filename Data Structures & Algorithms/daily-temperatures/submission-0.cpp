class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        deque<pair<int, int>>
            dq;  
        vector<int> res(n, 0);


        for (int i = 0; i < temperatures.size(); i++) {
            int curr = temperatures[i];
            while (!dq.empty() && (dq.back().first < curr)) {
                auto [temperature, idx] = dq.back();
                dq.pop_back();
                res[idx] = i-idx;
            }
            dq.push_back({curr, i});
        }

        return res;
    }
};
