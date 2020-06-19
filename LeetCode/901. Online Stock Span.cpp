#define pii pair<int,int>

class StockSpanner {
    stack <pii> s;
    int idx;
public:
    StockSpanner() {
        idx = 0;
    }

    // "find the maximum consecutive numbers who are less than or equal to this number"
    // This is another way of saying "Find a smaller number on it's left  whose index is
    // the closest"
    // Just do the opposite sign of "Largest rectangle in a histogram" problem

    int next(int price) {
        int ans = 0;


        // my goal is to remove top until i find a bigger element than this one
        // ! (s.top().first > price) --> missing the outer bracket can make your life hell.
        while (!s.empty() && !(s.top().first > price)) {
            s.pop();
        }

        if (s.empty()) {
            ans = idx + 1;
        } else {
            ans = idx - s.top().second;
        }

        s.push(make_pair(price, idx));
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */