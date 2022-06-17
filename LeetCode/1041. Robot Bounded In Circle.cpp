class Solution {
public:
    enum direction {
        NORTH = 0, 
        EAST = 1, 
        SOUTH = 2, 
        WEST = 3
    };
    
    bool isRobotBounded(string instructions) {
        
        // north, east, south, west
        vector<vector<int>> dir{{0,1}, {1,0}, {0,-1}, {-1,0}};  
        int dirIdx = 0; // 0 means north
        
        int x = 0, y = 0; 
        
        for(int i = 0 ; i < instructions.length() ; i++) {
            char currChar = instructions[i]; 
            
            if(currChar == 'G') {
                x = x + dir[dirIdx][0]; 
                y = y + dir[dirIdx][1]; 
            } else if (currChar == 'L') {
                dirIdx = ((dirIdx - 1) + 4) % 4; 
            } else if(currChar == 'R') {
                dirIdx = (dirIdx + 1) % 4; 
            }
        }
        
        if(dirIdx != NORTH || (x == 0 && y == 0)) {
            return true; 
        } 
        
        return false; 
    }
};