/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct myClass{
    bool operator()(const Interval& interval1, const Interval& interval2){
        return interval1.start < interval2.start;
    }
} my;
class Solution {
public:
    static bool myComp(const Interval& interval1, const Interval& interval2){
        return interval1.start < interval2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(!intervals.size()) return true;
        sort(intervals.begin(), intervals.end(), myComp);
        //sort(intervals.begin(), intervals.end(), [](const Interval& interval1, const Interval& interval2){ return interval1.start < interval2.start; }); // Lambda function
        for(int i = 0; i < intervals.size()-1; ++i)
            if(intervals[i].end > intervals[i+1].start) return false;
        
        return true;
    }
};
