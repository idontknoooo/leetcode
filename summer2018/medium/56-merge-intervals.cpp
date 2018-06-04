// 14ms
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {        
        vector<Interval> res;
        if(intervals.size()==0) return res;
        auto cmp = [] (Interval a, Interval b) { return a.start < b.start;};
        sort(intervals.begin(), intervals.end(), cmp);
        Interval tmp = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(tmp.end >= intervals[i].start){                
                tmp.end = max(tmp.end, intervals[i].end);                
            }
            else{
                res.push_back(tmp);
                tmp = intervals[i];                
            }
            
            //if(i == intervals.size()-1) res.push_back(tmp);
        }
        
        res.push_back(tmp);
        return res;        
    }
};

// 16ms
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(const Interval& a, const Interval& b){
        return a.start<b.start || a.start==b.start&&a.end<b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ans;
        for (int i=0; i<intervals.size(); i++) {
            if (!i || intervals[i].start > ans.back().end) ans.push_back(intervals[i]);
            else if (intervals[i].end <= ans.back().end) continue;
            else ans.back().end = intervals[i].end;
        }
        return ans;
    }
};
