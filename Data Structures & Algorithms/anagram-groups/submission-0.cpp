class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> group;
       vector<vector<string>> res;
       for(string s : strs){
         string cpy = s;
         sort(cpy.begin(), cpy.end());
         group[cpy].push_back(s);
       } 
       for(auto e : group){
        res.push_back(e.second);
       }
       return res;
    }
};
