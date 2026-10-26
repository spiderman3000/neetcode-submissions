class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> db;
        for(string str : strs){
            string cpy = str;
            sort(cpy.begin(),cpy.end());
            db[cpy].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto& [key, value] : db){
            res.push_back(value);
        }
        return res;
    }
};
