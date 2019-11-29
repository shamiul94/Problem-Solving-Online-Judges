#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d)for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs\n",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))

using namespace std;

// this class contains the data about transactions.
class transaction {
public:
    string name;
    int time;
    int amount;
    string city;
    bool alreadyTaken;

    transaction() {
        alreadyTaken = false;
    }

    transaction(string n, int t, int a, string c) {
        name = n;
        time = t;
        amount = a;
        city = c;
        alreadyTaken = false;
    }

    bool isAlreadyTaken() {
        return alreadyTaken;
    }

    bool operator<(const transaction &obj) {
        if (name == obj.name) {
            return time < obj.time;
        }
        return name.compare(obj.name) < 0;
    }
};

bool isConflicting(const transaction &a, const transaction &b) {
    return a.name == b.name && a.city != b.city && abs(a.time - b.time) <= 60;
}

string makeString(const transaction &t) {
    return t.name + "," + to_string(t.time) + "," + to_string(t.amount) + "," + t.city;
}

class Solution {
public:

    // time complexity becomes = O(n log n) + O(n) + O(n) = O(n log n + 2n) = O(n log n)
    // in the worst of worst case, it might be O(n^2)
    vector<transaction> solve(vector<transaction> &vec) {
        int n = vec.size();

        vector<transaction> ret;

        // if vector size is 1 or 0, there is no invalid transaction.
        // return empty vector.
        if (n == 0) return ret;
        if (n == 1) return ret;

        // sort the given vector based on their name.
        // if their name is equal, sort them based on time.
        // I overloaded the < operator in transaction class to do it.

        // O(n log n)
        sort(vec.begin(), vec.end());

        // if amount > 1000, mark it as taken and put it in the ret array.

        // O(n)
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].amount > 1000) {
                vec[i].alreadyTaken = true;
                ret.push_back(vec[i]);
            }
        }

        int lo = 0, hi;


        // sliding window :
        // idea:
        // suppose, the case is -
        // {alice, 50, 100, ny}, {alice, 80, 100, dhk}, {bob, 50, 100, ny}, {bob, 60, 100, ny}

        // Left(lo) to Right(hi)

        // total time complexity of this for loop = O(n) -> average case

        // O(n)
        for (hi = 1; hi < n; hi++) {
            // if a new name comes up, that means, any element before this element can't be conflicting with
            // this element as the array is sorted beforehand.
            // so, lo = hi

            // O(1)
            if (vec[hi].name != vec[hi - 1].name) {
                lo = hi;
                continue;
            }

            // our window needs to be such as, the highest indexed element and lowest indexed element mustn't be
            // more that 60 second time apart from each other.
            // so, we increase lo so that, (hi - lo) is always less than or equal to 0.

            // in general it should be O(1) or constant time.
            // but in worst case, where first n elements' time range is 60 but the n+1 th element
            // is out of that range, then for the last 'hi' element, it will be O(n)
            while (abs(vec[hi].time - vec[lo].time) > 60) {
                lo++;
            }


            // we check if the lo and hi elements are conflicting with each other.
            // if they are, we have to push them in a vector and compare the next lo element.
            //
            // but, if they are not, don't increase lo because, it might be conflicting to some other element which
            // we haven't seen yet by 'hi' variable. but, this arises a new problem.
            // suppose, our test case is -
            //
            // {a,10,100,x}, {a,10,100,y}, {a,10,100,x}, {a,10,100,x}, {a,10,100,x}, {a,10,100,x}
            //
            // at first, hi == 1 , lo == 0
            // hi and lo element will get a conflict. so,
            // hi becomes 2, lo becomes 1.
            // now, hi == 2, lo == 1
            // again, hi and lo gets a conflict as their name is similar but city is different.
            // so, again hi++, lo++
            // now, hi == 3, lo == 2
            // but this time, hi and lo doesn't get a conflict as they have same name, city and their
            // time difference is less than 60.
            // and similarly all the rest elements are not conflicted anymore.
            // this is a problem because, all these elements (from index 2-5 [0-based index]) are in a conflict
            // with 1-index element {a,10,100,y}.

            // this problem can be solved by running the same loop from left to right with some minor modification.
            // that is done in the next for loop. (marked with "RIGHT TO LEFT" comment).
            //


            // this also should be constant time as we are just checking the
            // window to compare. in worst case this window might be O(n) too.
            while (lo <= hi && isConflicting(vec[lo], vec[hi])) {
                if (!vec[lo].isAlreadyTaken()) {
                    vec[lo].alreadyTaken = true;
                    ret.push_back(vec[lo]);
                }
                if (!vec[hi].isAlreadyTaken()) {
                    vec[hi].alreadyTaken = true;
                    ret.push_back(vec[hi]);
                }

                lo++;
            }
        }



        // this loop will do the same thing as previous for loop but this time,
        // from right to left, so, the elements that were missing from comparison,
        // will be compared this time.
        // this will get the whole list of invalid items.


        // same as before = O(n)

        /*RIGHT TO LEFT*/
        hi = n - 1;
        // Right(hi) to Left(lo)
        for (lo = n - 2; lo >= 0; lo--) {
            if (vec[lo].name != vec[lo + 1].name) {
                hi = lo;
                continue;
            }

            while (abs(vec[hi].time - vec[lo].time) > 60) {
                hi--;
            }


            while (lo <= hi && isConflicting(vec[lo], vec[hi])) {

                if (!vec[hi].isAlreadyTaken()) {
                    vec[hi].alreadyTaken = true;
                    ret.push_back(vec[hi]);
                }

                if (!vec[lo].isAlreadyTaken()) {
                    vec[lo].alreadyTaken = true;
                    ret.push_back(vec[lo]);
                }

                hi--;
            }
        }

        return ret;
    }

    vector<string> invalidTransactions(vector<string> &transactions) {
        vector<transaction> vec;
        int n = transactions.size();

        // parse the string to make transaction class object.
        for (int i = 0; i < n; i++) {
            string tranString = transactions[i];
            tranString += ",";
            int strSize = tranString.size();
            string s = "";
            int partNo = 1;
            transaction t;
            for (int j = 0; j < strSize; j++) {
                if (tranString[j] == ',') {
                    if (partNo == 1) { // name
                        t.name = s;
                    } else if (partNo == 2) { // time
                        t.time = stoi(s);
                    } else if (partNo == 3) { // money
                        t.amount = stoi(s);
                    } else { // city
                        t.city = s;
                    }
                    partNo++;
                    s = "";
                } else {
                    s = s + tranString[j];
                }
            }

            vec.push_back(t);
        }

        vector<string> ret;
        vec = solve(vec);
        int N = vec.size();
        for (int i = 0; i < N; i++) {
            ret.push_back(makeString(vec[i]));
        }
        return ret;
    }
};


int main() {
    vector<string> vec;

    vec.push_back("alice,10,800,b");

    vec.push_back("alice,20,800,c");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");
    vec.push_back("alice,30,800,b");



//    vec.push_back("alice,80,100,xy");
//    vec.push_back("alice,140,800,yz");
//    vec.push_back("bob,140,800,yz");
//    vec.push_back("alice,140,800,yz");
//    vec.push_back("bob,500,800,yz");

    Solution s;
    time__("program time") {
        vec = s.invalidTransactions(vec);
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << endl;

    return 0;
}