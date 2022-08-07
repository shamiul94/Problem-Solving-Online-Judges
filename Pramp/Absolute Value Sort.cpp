/**
Absolute Value Sort
Given an array of integers arr, write a function absSort(arr),
 that sorts the array according to the absolute values of the numbers in arr.
  If two numbers have the same absolute value, sort them according to sign,
  where the negative numbers come before the positive numbers.

Examples:

input:  arr = [2, -7, -2, -2, 0]
output: [0, -2, -2, 2, -7]
Constraints:

[time limit] 5000ms
[input] array.integer arr
0 ≤ arr.length ≤ 10
[output] array.integer
 *
 */

#import <iostream>
#import <vector>

#define pii pair<int, int>

using namespace std;

class comparator
{
public:
    bool operator()(pii p1, pii p2)
    {
        if (p1.second < p2.second)
        {
            return true;
        }
        else if (p1.second > p2.second)
        {
            return false;
        }
        else
        {
            return p1.first < p2.first;
        }
    }
};

vector<int> absSort(const vector<int> &arr)
{
    vector<pii> pairVector;

    for (int i = 0; i < arr.size(); i++)
    {
        pairVector.push_back({arr[i], abs(arr[i])});
    }

    sort(pairVector.begin(), pairVector.end(), comparator());

    vector<int> result;

    for (int i = 0; i < pairVector.size(); i++)
    {
        result.push_back(pairVector[i].first);
    }

    return result;
}

int main()
{
    return 0;
}

/**

2 -7 -2 -2 0

{2, 2}, {-7, 7}, {-2, 2}, {-2, 2}, {0,0}

// element - n --> O(nlogn)
// space - O(n)


first - given value, secons - absolute value

0 -2 -2 2 -7


*/