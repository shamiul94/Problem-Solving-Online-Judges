#include <bits/stdc++.h>
using namespace std;


void findAllCobinationOfTarget(
		vector<vector<int>> &allCombinations,
		vector<int> &currCombination,
		int prevNum,
		int currNum
	) {
		
	if(currNum < 0) {
		return; 
	}
	
	if(currNum == 0) {
		allCombinations.push_back(currCombination);
		return;
	}
	
	for(int i = prevNum; i <= currNum; i++) {
		currCombination.push_back(i); 
		findAllCobinationOfTarget(allCombinations, currCombination, i, currNum-i); 
		currCombination.pop_back(); 
	}
}


int main() {
	vector<vector<int>> allCombinations; 
		vector<int> currCombination; 
		int prevNum = 1; 
		int currNum = 10; 
		
	// your code goes here
	findAllCobinationOfTarget(allCombinations, currCombination, prevNum, currNum); 
	
	
	for(int i = 0 ; i < allCombinations.size(); i++) {
		for(int j = 0 ; j < allCombinations[i].size(); j++) {
			cout << allCombinations[i][j] << " " ; 
		}
		cout << endl; 
	}
	
	return 0;
}