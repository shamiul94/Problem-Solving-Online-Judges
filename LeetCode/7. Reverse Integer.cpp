// without long 

// gives warning as there is an overflow
class Solution {
public:
    int reverse(int x) {
        int ans = 0 ; 

        while(x){
            int tem = ans * 10 + x % 10; 
            
            if(tem / 10 != ans) return 0; 
            
            ans = tem; 
            x = x / 10; 
        }

        // cout << ans << endl; 
        return ans; 
    }
};


//// with long 


class Solution {
public:
    int reverse(int x) {
        long n = 0;
        long xx = x;
        int sign = 1;
        if (x < 0) sign = -1;

        xx = abs(xx);
        while (xx != 0) {
            int d = xx % 10;
            n = n * 10 + d;
            xx = xx / 10;
        }

        n = sign * n;

        if (n > INT_MAX || n < INT_MIN) return 0;
        return n;
    }
};