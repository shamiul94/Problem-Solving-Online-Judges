class Solution {
public:
    int lengthLongestPath(string input) {
        string currString = ""; 
        
        vector<string> splitStrings; 
        
        for(int i = 0; i < input.length(); i++) {
            if(input[i] != '\n') {
                currString += input[i];
                continue;
            } 
            
            splitStrings.push_back(currString); 
            currString = "";
        }
        
        splitStrings.push_back(currString); 
        
        stack<int> lengthStack; 
        
        currString = "";
        
        int maxDirectoryLength = 0; 
        
        for(int i = 0; i < splitStrings.size(); i++) {
            currString = splitStrings[i]; 
            
            int countTabs = 0; 
            
            for(int j = 0; j < currString.size(); j++) {
                if(currString[j] == '\t') {
                    countTabs++; 
                }
            }
            
            
            int currLevel = countTabs + 1; 
            
            while(true) {
                if(lengthStack.size() >= currLevel) {
                    lengthStack.pop();
                } else {
                    break;
                }
            }
            
            int currStringLenWithoutTabs = currString.length() - countTabs;
            
            int lengthTillNowFromStack = lengthStack.empty()? 0: lengthStack.top(); 
            
            if(currString.find('.') != std::string::npos){
                maxDirectoryLength = max(maxDirectoryLength, lengthTillNowFromStack + currStringLenWithoutTabs);
            }
            
            int currLengthTillNow = 0; 
            
            if(currString.find('.') == std::string::npos) {
                currLengthTillNow = lengthTillNowFromStack + currStringLenWithoutTabs + 1; // to add '/' in path
            } else {
                currLengthTillNow = lengthTillNowFromStack + currStringLenWithoutTabs;
            }
            
            lengthStack.push(currLengthTillNow);
            
        }
        
        return maxDirectoryLength;
    }
};