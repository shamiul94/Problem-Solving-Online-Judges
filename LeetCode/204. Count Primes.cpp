class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0; 
        
        vector<bool> isPrime(n, true);
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        int sqr = sqrt(n); 
        
        for(int i = 4 ; i < n; i+=2) {
            isPrime[i] = false; 
        }
        
      
        
        for(int i = 3; i <= sqr; i+=2) {
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false; 
                }
            }
        }
        
        int ans = 0; 
        
        for(int i = 1; i < n; i++) {
            if(isPrime[i]) {
                ans++; 
            }
        }
        
        return count(isPrime.begin(), isPrime.end(), true);
    }
};