class Solution {
    unordered_map<char, int> orderVal;

    bool isLessThan(string a, string b) {
        int i = 0;
        cout << a << "_" << b << endl;
        while (i < a.size() && i < b.size()) {
            if (orderVal[a[i]] < orderVal[b[i]]) {
                return true;
            } else if (orderVal[a[i]] == orderVal[b[i]]){
                i++;
                continue;
            }
            return false;
        }
        if (a.size() > b.size()) {
            return false;
        }

        return true;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            orderVal[order[i]] = i;
        }
        for (int i = 0; i + 1 < words.size(); i++) {
            if (!isLessThan(words[i], words[i + 1])) {
                return false;
            }
        }

        return true;
    }
};