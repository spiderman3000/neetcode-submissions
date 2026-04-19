class Solution {
    char DELIMITER = '#';
public:
    string encode(vector<string>& strs) {
        string result = "";
        int n = strs.size();
        for(int i=0;i<n;i++){
            string s = strs[i];
            int m = s.size();
            result += to_string(m) + DELIMITER + s;
        }
    
        return result;
    }

    vector<string> decode(string s) {
        // cout << s << endl;
        vector<string> result;
        int currStringLength = 0;
        int i = 0;
        while(i < s.size()){
            int nextStringLength = 0;
            string nextNum = "";
            while(s[i] != DELIMITER){
                nextNum = nextNum + s[i];
                i++;
            }
            // cout << nextNum << "#" << endl;
            if(nextNum != ""){
             nextStringLength = std::stoi(nextNum);
            }
            // cout << nextStringLength << "spiderman" << endl;
            currStringLength = nextStringLength;
            i++; // move from # to next string start

            string currWord = "";
            while(currStringLength){
                currStringLength--;
                currWord += s[i];
                i++;
            }
            // cout << i << "#" << endl;
            // cout << currWord << "batman#" << endl;
            if(i != 0){
                result.push_back(currWord);
            }
        }
        return result;
    }
};
