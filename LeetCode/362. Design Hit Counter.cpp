class HitCounter {
public:
    list<pair<int, int> > dq; 
    int total; 
    
    HitCounter() {
        total = 0; 
    }
    
    void hit(int timestamp) {
        if(dq.empty()) {
            dq.push_back({timestamp, 1}); 
        } else {
            pair<int,int> last = dq.back(); 
            if(last.first == timestamp){
                dq.back().second++; 
            } else {
                dq.push_back({timestamp, 1});
            }
        }
        
        total++; 
    }
    
    int getHits(int timestamp) {
        while(!dq.empty()) {
            pair<int, int> front = dq.front(); 
            if(timestamp - front.first >= 300) {
                total -= front.second; 
                dq.pop_front(); 
            } else {
                break; 
            }
        }
        
        return total; 
    }
};


class HitCounter1 {
public:
    deque<pair<int, int> > dq; 
    int total; 
    
    HitCounter1() {
        total = 0; 
    }
    
    void hit(int timestamp) {
        if(dq.empty()) {
            dq.push_back({timestamp, 1}); 
        } else {
            pair<int,int> last = dq.back(); 
            if(last.first == timestamp){
                dq.back().second++; 
            } else {
                dq.push_back({timestamp, 1});
            }
        }
        
        total++; 
    }
    
    int getHits(int timestamp) {
        while(!dq.empty()) {
            pair<int, int> front = dq.front(); 
            if(timestamp - front.first >= 300) {
                total -= front.second; 
                dq.pop_front(); 
            } else {
                break; 
            }
        }
        
        return total; 
    }
};


/**

1 2 3 4 300 302 307...

3 4 300 302 303


*/

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */