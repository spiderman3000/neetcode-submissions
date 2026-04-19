class Solution {
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] == s[r--]) continue;
            return false;
        }
        return true;
    }

   public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            return isPalindrome(s.substr(0, l) + s.substr(l + 1, s.size() - l - 1)) ||
                   isPalindrome(s.substr(0, r) + s.substr(r + 1, s.size() - r - 1));
        }
        return true;
    }
};