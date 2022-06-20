class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> begins; 
        vector<int> ends; 
        
        
       for(int i = 0; i < intervals.size(); i++) {
           begins.push_back(intervals[i][0]); 
           ends.push_back(intervals[i][1]); 
       }
        
        sort(begins.begin(), begins.end()); 
        
        
        sort(ends.begin(), ends.end());
        
        int beginPointer = 0, endPointer = 0; 
        
        int rooms = 0; 
        
        while(beginPointer < begins.size()) {
            if(begins[beginPointer] < ends[endPointer]) {
                rooms++; 
            } else {
                endPointer++; 
            }
            
            beginPointer++; 
        }
        
        return rooms;
    }
};


////////////////////////

class Comparator {
    public: 
    bool operator() (vector<int> &v1, vector<int> &v2) {
        return v1[1] > v2[1]; 
    }
};


bool vectorComparator(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0]; 
}

class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), vectorComparator);
        
        
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq; // min heap 
        
        int rooms = 0; 
        
        for(int i = 0; i < intervals.size(); i++) {
            // cout << "(" << intervals[i][0] << "," << intervals[i][1] << "),"; 
            
            vector<int> currInterval = intervals[i]; 
            
            if(pq.empty()) {
                rooms++; 
                pq.push(currInterval); 
                continue; 
            }
            
            vector<int> currTop = pq.top(); 
            
            if(currTop[1] > currInterval[0]) {
                rooms++; 
            } else {
                pq.pop(); 
            }
            
            pq.push(currInterval);
        }
        
        return rooms; 
    }
};

////////////////

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<int> starts;
        vector<int> ends;

        for (int i = 0; i < intervals.size(); i++)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int currEnd = 0;

        for (int i = 0; i < starts.size(); i++)
        {
            if (starts[i] < ends[currEnd])
            {
                rooms++;
            }
            else if (starts[i] >= ends[currEnd])
            {
                currEnd++;
            }
        }
        return rooms;
    }
};