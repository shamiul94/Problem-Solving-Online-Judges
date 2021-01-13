class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0) return 0; 
        if(stones.size() == 1) return stones[0]; 
        
        priority_queue<int> pq; 
        
        for(int i = 0 ; i < stones.size(); i++){
            pq.push(stones[i]); 
        }
        
        while(pq.size() > 1){
            int x,y,diff; 
            y = pq.top(); 
            pq.pop(); 
            x = pq.top(); 
            pq.pop(); 
            diff = y - x; 
            pq.push(diff); 
            // cout << x << " " << y << " " << diff << "-" << pq.size() << endl; 
        }
        return pq.top(); 
    }
};