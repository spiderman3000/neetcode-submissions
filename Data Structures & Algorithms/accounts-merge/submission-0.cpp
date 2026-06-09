class DSU{
public: 
    vector<int> parent; // idx = accounts[i][0] 
    vector<int> rank;

    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n,0);
        for(int i=0;i <n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unionSets(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(rank[pu] < rank[pv]) {
            swap(u, v);
            swap(pu, pv);
        }
        rank[pu] += rank[pv];
        parent[pv] = pu;
        return true;
    }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n); // accounts[i] = idx i in dsu
        unordered_map<string, int> emailToAccountIdx; 

        for(int i=0;i<accounts.size();i++){
            // string name = accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(emailToAccountIdx.count(email)){
                    int originalIdx = emailToAccountIdx[email];
                    dsu.unionSets(i, originalIdx);
                } else {
                    emailToAccountIdx[email] = i;
                }
            }
        }

        vector<vector<string>> res;
        unordered_map<int, set<string>> mp;
        for(auto [email, accountIdx] : emailToAccountIdx){
            int parent = dsu.find(accountIdx);
            mp[parent].insert(email);
        }

        for(auto [idx, emails]: mp){
            res.push_back({accounts[idx][0]});
            for( string s : emails){
                res.back().push_back(s);
            }
        }


        return res;
    }
};