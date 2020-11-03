class Solution {
public:
    vector<double> cumulated_w;
    
    Solution(vector<int>& w) {
        // cout << w.size() << endl; 
        
        cumulated_w.push_back(w[0]); 
        for(int i = 1 ; i < w.size(); i++){
            cumulated_w.push_back(w[i] + w[i-1]); 
        }
        
    }
    
    int pickIndex() {
        // for(int i = 0 ; i < wf.size(); i++){
        //     // cout << "hi"; 
        //     cout << wf[i] << ", " ; 
        // }
        // cout << endl; 
        
        int n = cumulated_w.size(); 
        
        int random = ((int) rand()) % cumulated_w[n-1]; 
        // cout << random << endl; 
        int lo = 0 , hi = cumulated_w.size() - 1; 
        int idx = 0 ; 
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2; 
            
            if(random > cumulated_w[mid]){
                lo = mid + 1; 
            } else if(random < cumulated_w[mid]){
                idx = mid; 
                hi = mid - 1; 
            }
        }
        return idx; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */


class Solution2 {
public:
    vector<double> wf;
    
    Solution(vector<int>& w) {
        // cout << w.size() << endl; 
        int sum = 0 ; 
        for(int i = 0 ; i < w.size(); i++){
            sum = sum + w[i]; 
        }
        
        for(int i = 0 ; i < w.size(); i++){
            wf.push_back(w[i]*1.0/sum); 
        }
        
        for(int i = 1 ; i < w.size(); i++){
            wf[i] = wf[i] + wf[i-1];  
        }
        
    }
    
    int pickIndex() {
        // for(int i = 0 ; i < wf.size(); i++){
        //     // cout << "hi"; 
        //     cout << wf[i] << ", " ; 
        // }
        // cout << endl; 
        
        double random = ((double) rand() / (RAND_MAX));  
        // cout << random << endl; 
        int lo = 0 , hi = wf.size() - 1; 
        int idx = 0 ; 
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2; 
            
            if(random > wf[mid]){
                lo = mid + 1; 
            } else if(random < wf[mid]){
                idx = mid; 
                hi = mid - 1; 
            }
        }
        return idx; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */