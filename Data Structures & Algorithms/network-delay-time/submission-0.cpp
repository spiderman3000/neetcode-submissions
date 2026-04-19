class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        pq.push({0, k});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int ctime = t.first;
            int cnode = t.second;
            // if(ctime > time[cnode]) continue;
            vector<pair<int,int>> neighbours = graph[cnode];
            for(int i=0;i<neighbours.size();i++){
                pair<int,int> neighbour = neighbours[i];
                if(time[neighbour.first] > ctime+neighbour.second){
                    time[neighbour.first] = ctime+neighbour.second;
                    pq.push({ctime+neighbour.second, neighbour.first});
                }
            }
        }

        int minTime = 0;
        for(int i=1;i<time.size();i++){
            if(time[i] == INT_MAX) return -1;
            minTime = max(minTime, time[i]);
        }
        return minTime;
    }
};