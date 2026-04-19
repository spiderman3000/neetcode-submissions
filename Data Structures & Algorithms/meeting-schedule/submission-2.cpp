/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    bool isOverlapping(Interval i1, Interval i2){
        if(i1.start <= i2.start && i1.end >= i2.end) return true;
        if(i2.start <= i1.start && i2.end >= i1.end) return true;
        if(i1.start > i2.start && i1.start < i2.end) return true;
        if(i2.start > i1.start && i2.start < i1.end) return true;
        return false;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        for(int i=0;i<intervals.size();i++){
            for(int j=i+1;j<intervals.size();j++){
                Interval i1 = intervals[i];
                Interval i2 = intervals[j];
                if(isOverlapping(i1,i2)) return false;
            }
        }

        return true;
    }
};
