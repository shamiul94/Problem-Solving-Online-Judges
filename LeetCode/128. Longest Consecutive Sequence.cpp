class Solution {
public:

    // my solution
    // 65%, 76%
    int longestConsecutive2(vector<int> &nums) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
        }

        int maxLongestSeq = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current, prev, next, currSeqLen;
            current = nums[i];
            prev = current - 1;
            next = current + 1;
            currSeqLen = 1; // for the number itself.

            while (us.find(prev) != us.end()) {
                currSeqLen++;
                us.erase(prev);
                prev--;
            }

            while (us.find(next) != us.end()) {
                currSeqLen++;
                us.erase(next);
                next++;
            }

            maxLongestSeq = max(maxLongestSeq, currSeqLen);
        }
        return maxLongestSeq;
    }


    ///

    // better solution
    // 98%, 76%

    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
        }

        int maxLongestSeq = 0;
        for (int i = 0; i < nums.size(); i++) {

            int current, next, currSeqLen;
            current = nums[i];
            next = current + 1;
            currSeqLen = 1; // for the number itself.

            // for optimizing.
            //  look for such an element, whose previous is
            // not found in the set. that means, it's the first
            // element of the consecutive sequence (if it exists).
            // so, start from here and look for all the next
            // elements in the set. if the immediate previous element is found,
            // ignore it because, it's not the
            // start of any sequence, so, it has been counted once.
            // it optimizes the solution.
            if (us.find(current - 1) != us.end()) continue;


            while (us.find(next) != us.end()) {
                currSeqLen++;
                next++;
            }

            maxLongestSeq = max(maxLongestSeq, currSeqLen);
        }
        return maxLongestSeq;
    }

};


//////////////



