#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int maxN, minN;
        char maxC, minC;

        maxN = max(A,B);
        minN = min(A,B);

        if(A == maxN){
            maxC = 'a';
            minC = 'b';
        } else {
            maxC = 'b';
            minC = 'a';
        }
//        cout <<

        string ans ;
        int N = A+B;

        if(maxN == minN || maxN == minN+1 || maxN == minN + 2){ // n,n
            for(int i = 0 ; i < N; i++){
                if(i%2 == 0){
                    ans += maxC;
                    maxN--;
                } else {
                    if(minN > 0){
                        ans += minC;
                        minN--;
                    } else {
                        ans += maxC;
                        maxN--;
                    }
                }
            }
        }  else if(maxN == 2 * minN || maxN == 2 * minN + 1 || maxN == 2 * minN + 2) {// n , 2n
            for(int i = 0 ; i < N; i++){
                if((i+1)%3 == 0 && minN > 0){
                    ans += minC;
                    minN--;
                } else {
                    ans+= maxC;
                    maxN--;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.strWithout3a3b(4,1);
}