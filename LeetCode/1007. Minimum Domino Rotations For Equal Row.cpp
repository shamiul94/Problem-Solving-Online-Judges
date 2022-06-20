class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> um; // idx, count 
        
        int maxCount = 0; 
        int maxOccurredNumber = 0; 
        
        for(int i = 0; i < tops.size(); i++) {
            int currTop = tops[i];
            
            if(um.find(currTop) == um.end()) {
                // not found 
                um[currTop] = 1; 
            } else {
                um[currTop]++; 
            }
            
            if(um[currTop] > maxCount) {
                maxCount = maxCount, um[currTop]; 
                maxOccurredNumber = currTop; 
            }
        }
        
        
        for(int i = 0; i < bottoms.size(); i++) {
            int currBottom = bottoms[i];
            
            if(um.find(currBottom) == um.end()) {
                // not found 
                um[currBottom] = 1; 
            } else {
                um[currBottom]++; 
            }
            
            if(um[currBottom] > maxCount) {
                maxCount = um[currBottom]; 
                maxOccurredNumber = currBottom; 
            }
        }
        if(maxCount < tops.size()) return -1; 
        
        int nonMatchingPairs = 0; 
        
        int maxNonPairlyOccurredInTops = 0; 
        int maxNonPairlyOccurredInBottoms = 0; 
        
        for(int i = 0; i < tops.size(); i++) {
            if(tops[i] != maxOccurredNumber && bottoms[i] != maxOccurredNumber) return -1; 
            
            if(tops[i] == bottoms[i]) continue; 
            
            if(tops[i] == maxOccurredNumber) maxNonPairlyOccurredInTops++; 
            if(bottoms[i] == maxOccurredNumber) maxNonPairlyOccurredInBottoms++; 
        }
        
        return min(maxNonPairlyOccurredInTops, maxNonPairlyOccurredInBottoms);
    }
};