
bool compare(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution1 {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector <vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.size() == 0) {
                ans.push_back(intervals[i]);
                continue;
            }

            vector<int> first = ans.back();
            ans.pop_back();
            vector<int> second = intervals[i];

            if (second[0] > first[1]) {
                ans.push_back(first);
                ans.push_back(second);
            } else {
                vector<int> v;
                v.push_back(first[0]);
                v.push_back(max(first[1], second[1]));
                ans.push_back(v);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector <vector<int>> ans;

        vector<int> extended;
        vector<int> second;

        if (intervals.size() == 0) return ans;

        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) {
                extended = intervals[i];
                continue;
            }

            second = intervals[i];

            if (second[0] > extended[1]) {
                ans.push_back(extended);
                extended = second;
            } else {
                extended[1] = max(extended[1], second[1]);
            }
        }
        ans.push_back(extended);
        return ans;
    }
};

//////
class Comparator{
    public: 
        bool operator() (vector<int> &v1, vector<int> &v2) {
            return v1[1] < v2[1]; // max heap 
        }  
};


class VectorComparator {
    public: 
    bool operator() (vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0]; // ascending sort - 1,2,3,4...
    }  
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return vector<vector<int>> (); 
                
        sort(intervals.begin(), intervals.end(), VectorComparator()); 
        
        
        vector<vector<int>> result; 
        vector<int> mergedInterval(2); 
        
        vector<int> prevInterval = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> currInterval = intervals[i]; 
            
            
            if(prevInterval[1] > currInterval[1]) {
                mergedInterval[0] = prevInterval[0]; 
                mergedInterval[1] = prevInterval[1]; 
                
                prevInterval = mergedInterval;
                
                continue; 
            } else if(prevInterval[1] <= currInterval[1] && prevInterval[1] >= currInterval[0]) {
                mergedInterval[0] = prevInterval[0]; 
                mergedInterval[1] = currInterval[1]; 
                
                prevInterval = mergedInterval;
                
                continue; 
            }
            
            result.push_back(prevInterval);
            prevInterval = currInterval; 
        }
        
        result.push_back(prevInterval);
        
        
        return result; 
    }
};



class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return vector<vector<int>> (); 
        
        priority_queue<vector<int>, vector<vector<int>>> pq; 
        
        sort(intervals.begin(), intervals.end(), VectorComparator()); 
        
        pq.push(intervals[0]); 
        
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> currInterval = intervals[i]; 
            
            vector<int> currTop = pq.top(); 
            
            vector<int> mergedInterval(2); 
            
            if(currTop[1] > currInterval[1]) {
                mergedInterval[0] = currTop[0]; 
                mergedInterval[1] = currTop[1]; 
                pq.pop(); 
                pq.push(mergedInterval); 
                
                continue; 
            } else if(currTop[1] <= currInterval[1] && currTop[1] >= currInterval[0]) {
                mergedInterval[0] = currTop[0]; 
                mergedInterval[1] = currInterval[1]; 
                pq.pop(); 
                pq.push(mergedInterval); 
                
                continue; 
            }
            
            
            pq.push(currInterval); 
        }
        
        vector<vector<int>> result; 
        
        while(!pq.empty()) {
            result.push_back(pq.top()); 
            pq.pop(); 
        }
        
        return result; 
    }
};