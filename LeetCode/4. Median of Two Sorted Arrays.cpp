class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        /*
1, 3, 6, 8 --> m
2, 4, 5, 7 --> n
*/

        int m = nums1.size(), n = nums2.size();
        int len = m + n;

        priority_queue<pair<int, int>> pq; // <value, arr_no>

        int med1 = 0, med2 = 0;
        // n1 == 1
        // n2 == null
        if (nums1.size() != 0) {
            pq.push(make_pair(nums1[0], 1));
            med1 = nums1[0];
        }
        if (nums2.size() != 0) {
            pq.push(make_pair(nums2[0], 2));
            med2 = nums2[0];
        }

        int tem = med1;

        med1 = min(tem, med2);
        med2 = max(tem, med2);

        int i = 0;
        int j = 0;
        int maxLoop = (m + n) / 2 + 1;
        int loop = 0;
        while (!pq.empty() && loop <= maxLoop) {
            pair<int, int> t;
            t = pq.top();
            pq.pop();

            med1 = med2;
            med2 = t.first;
            int arr_no = t.second;

            if (arr_no == 1) {
                i++;
                if (i <= m - 1) {
                    pq.push(make_pair(nums1[i], 1));
                }
            } else if (arr_no == 2) {
                j++;
                if (j <= n - 1) {
                    pq.push(make_pair(nums2[j], 2));
                }
            }
            loop++;
        }

        double med;
        if ((m + n) % 2 == 0) { // even
            med = (med1 + med2) / 2.0;
        } else {
            med = med2;
        }

        return med;
    }
};
