class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> minDist(n, INT_MAX);
        vector<int> stopsArr(n, INT_MAX); // mins stops required to reach the ith node
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        
        pq.push({0, src, 0});
        minDist[src] = 0;
        stopsArr[src] = 0;

        unordered_map<int, vector<pair<int,int>>> graph;
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        while(!pq.empty()){
            auto [cost, node, stops] = pq.top();
            pq.pop();
            if(node == dst) return cost;
            if(stops > k) continue;
            auto& neigh = graph[node];
            for(int i=0;i<neigh.size();i++){
                auto [nextFlight, nextCost] = neigh[i];
                if(minDist[nextFlight] > nextCost + cost || stopsArr[nextFlight] > stops + 1){
                    pq.push({nextCost + cost, nextFlight, stops + 1});
                    minDist[nextFlight] = nextCost + cost;
                    stopsArr[nextFlight] = stops + 1;
                }
            }
        }

        return -1;
    }
};