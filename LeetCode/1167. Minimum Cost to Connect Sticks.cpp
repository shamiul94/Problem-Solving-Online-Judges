class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq; 
        
        for(int i = 0; i < sticks.size(); i++) {
            pq.push(sticks[i]); 
        }
        
        int cost = 0; 
        
        while(pq.size() > 1) {
            int stick1 = pq.top(); 
            pq.pop(); 
            
            int stick2 = pq.top(); 
            pq.pop(); 
            
            cost += (stick1 + stick2); 
            
            pq.push(stick1 + stick2);
        }
        
        return cost; 
    }
};