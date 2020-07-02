#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    multiset<double> ms;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        ms.insert((double)num);
    }

    double findMedian() {
        int n = ms.size()-1;
        auto it = ms.begin();
        if (ms.size() % 2 != 0) {
            for (int i = 0; i < n / 2; i++) {
                it++;
            }
            return *it;
        } else {
            for (int i = 0; i < n / 2; i++) {
                it++;
            }
            double a, b;

            a = *it;
            it++;
            b = *it;
            // cout << a << " " << b << endl; 
            return (a + b) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder *mf = new MedianFinder();
    mf->addNum(8);
    mf->addNum(2);//
    // 2 8
    cout << mf->findMedian() << endl;
    //-> 1.5
    mf->addNum(3); //
    mf->addNum(5); //
    mf->addNum(1);//
    mf->addNum(6); // 
    mf->addNum(2);//
    mf->addNum(9);
    mf->addNum(5);//
    mf->addNum(10);//
    mf->addNum(11);//
    mf->addNum(12);//
    // 1 2 2 3 5 5 6 8 9 10 11 12
    cout << mf->findMedian() << endl;
    //-> 2

    return 0;
}