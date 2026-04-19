class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<string, vector<int>>
            result; // can use set<string> then serialize/deserialize
        unordered_map<int, int> record;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            record[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                int target = -1 * (nums[i] + nums[j]);
                if (record.find(target) != record.end()) {
                    if (target == nums[i] && target == nums[j]) {
                        if (!(record[target] > 2)) {
                            continue;
                        }
                    } else if (target == nums[i] || target == nums[j]) {
                        if (!(record[target] > 1)) {
                            continue;
                        }
                    }
                    vector<int> v({nums[i], nums[j], target});
                    sort(v.begin(), v.end());
                    string s = "";
                    for (int k = 0; k < 3; k++) {
                        s = s + to_string(v[k]) + "#";
                    }
                    if (result.find(s) == result.end()) {
                        result[s] = v;
                    }
                }
            }
        }

        vector<vector<int>> output;
        for (auto pair : result) {
            output.push_back(pair.second);
        }
        return output;
    }
};