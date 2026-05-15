class Solution {
    char getNext(char ch){ if(ch == '9') return '0'; return ch+1; }
    char getPrev(char ch){ if(ch == '0') return '9'; return ch-1; }
    bool isDeadend(string curr, vector<string>& deadends){
        for(string s: deadends){
            if(curr == s) return true;
        }
        return false;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        if(isDeadend("0000", deadends)) return -1;
        if(target == "0000") return 0;

        // bfs from "0000" to target
        queue<string> q;
        q.push("0000");
        unordered_map<string, bool> visited;
        visited["0000"] = true;
        int dist = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == target){
                    return dist;
                }
                for(int i=0;i<4;i++){
                    string tmpNext = curr;
                    string tmpPrev = curr;
                    char chNext = getNext(curr[i]);
                    tmpNext[i] = chNext;
                    char chPrev = getPrev(curr[i]);
                    tmpPrev[i] = chPrev;

                    if(!visited[tmpNext] && !isDeadend(tmpNext, deadends)){
                        q.push(tmpNext);
                        visited[tmpNext] = true;
                    }
                    if(!visited[tmpPrev] && !isDeadend(tmpPrev, deadends)){
                        q.push(tmpPrev);
                        visited[tmpPrev] = true;
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};