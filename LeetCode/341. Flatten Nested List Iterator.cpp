/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    vector<NestedInteger> nestedList;
    int index;
    vector<int> flatList;

    void flatten(NestedInteger &nestedInt)
    {
        if (nestedInt.isInteger())
        {
            flatList.push_back(nestedInt.getInteger());
            return;
        }

        vector<NestedInteger> nestedList = nestedInt.getList();

        for (int i = 0; i < nestedList.size(); i++)
        {
            flatten(nestedList[i]);
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        this->nestedList = nestedList;
        this->index = 0;

        for (int i = 0; i < this->nestedList.size(); i++)
        {
            flatten(this->nestedList[i]);
        }

        // for(int i = 0 ; i < flatList.size(); i++) {
        //     cout << flatList[i] << endl;
        // }
    }

    int next()
    {
        return flatList[index++];
    }

    bool hasNext()
    {
        return index < flatList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */