#define pii pair<int, int>  // {numOfBox, unitPerBox}
#define vi vector<int>

class comparator {
    public:
        bool operator() (vi &p1, vi &p2) {
            return p1[1] > p2[1]; 
        }
}; 

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator()); 
        
        int totalUnits = 0; 
        
        for(int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            vi currBox = boxTypes[i]; 
            if(currBox[0] <= truckSize) {
            // cout << currBox[0] << " " << currBox[1] << endl; 
                
                truckSize -= currBox[0]; 
                totalUnits += (currBox[1] * currBox[0]); 
            } else {
            // cout << currBox[0] << " " << currBox[1] << " " << truckSize << endl; 
                
                totalUnits += (currBox[1] * truckSize); 
                truckSize = 0; 
                
            }
        }
        
        return totalUnits; 
    }
};