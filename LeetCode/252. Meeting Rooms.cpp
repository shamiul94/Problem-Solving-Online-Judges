
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) -> bool {
            return v1[0] < v2[0]; 
        }); 
        
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};