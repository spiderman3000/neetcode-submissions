#define ll long long

class Solution {
   public:
    int mySqrt(int x) {
        int res = 0;
        int l = 0, r = x;
        while (l <= r) {
            int m = l + (r - l) / 2;
            ll sq = (ll) m * m;
            if (sq > (ll) x) {
                r = m - 1;
            } else if (sq < (ll) x) {
                res = m;
                l = m + 1;
            } else {
                return m;
            }
        }
        return res;
    }
};