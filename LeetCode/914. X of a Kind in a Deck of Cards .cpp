class Solution {
public:
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }


    bool hasGroupsSizeX1(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        vector<int> counter;

        int prev = deck[0], same = 0, minCount = INT_MAX;

        for(int i = 0 ; i < deck.size(); i++){

            // cout << prev << " " << deck[i] << endl; 
            if(deck[i] == prev){
                same++;
            } else {
                minCount = min(minCount, same);
                counter.push_back(same);
                same = 1;
                prev = deck[i];
            }
        }

        // 1 1 1 1 2 2 2 2 2 2 2

        counter.push_back(same);
        minCount = min(minCount, same);

        int gcd2 = counter[0] ;
        for(int i = 1 ; i < counter.size(); i++){
            gcd2 = gcd(gcd2, counter[i]);
        }

        // cout << gcd2 << endl;
        return gcd2 >= 2;

    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }
};