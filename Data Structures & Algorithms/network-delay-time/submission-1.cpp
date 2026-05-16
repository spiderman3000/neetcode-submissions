#define graph unordered_map<int, vector<pair<int,int>>>
#define node int
#define delay int 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> timeTaken(n+1, INT_MAX); // time taken to reach ith node
        priority_queue<pair<delay, node>, vector<pair<delay,node>>, greater<>> pq;
        graph g;

        for(int i=0;i<times.size();i++){
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        pq.push({0, k});
        timeTaken[k] = 0;
        while(!pq.empty()){
            auto [currDelay, currNode] = pq.top();
            pq.pop();
            auto& nextNodes = g[currNode];
            for(int i=0;i<nextNodes.size();i++){
                auto [nextNode, nextDelay] = nextNodes[i];
                if(timeTaken[nextNode] > (currDelay + nextDelay)){
                    timeTaken[nextNode] = currDelay + nextDelay;
                    pq.push({currDelay+nextDelay, nextNode});
                }
            }
        }

        int res = 0;
        for(int i=1;i<n+1;i++){
            cout << i << " " << timeTaken[i] << endl;
            if(timeTaken[i] == INT_MAX) return -1;
            res = max(timeTaken[i], res);
        }

        return res;
    }
};
