// this solution is 100% memory-wise.
// but time-wise it's too bad. 5% only. it's because while choosing
// random element, we are increasing the iterator in O(n).
// we can reduce this time if we use an additional vector. and swap and erase the last
// element every time we remove an element.

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> u;

    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (u.find(val) == u.end()) {
            u.insert(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (u.find(val) != u.end()) {
            u.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        unordered_set<int>::iterator it, it2;
        int len = u.size();
        it = u.begin();

        int ran = rand() % len;
        for (int i = 0; i < ran; i++) it++;

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// better approach with unordered_map and vector