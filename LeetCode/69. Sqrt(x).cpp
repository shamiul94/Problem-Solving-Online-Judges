
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        int lo = 0;
        int hi = x;
        int mid;
        int ans;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (mid == x / mid)
            {
                ans = mid;
                break;
            }
            else if (mid < x / mid && (mid + 1) > x / (mid + 1))
            {
                ans = mid;
                break;
            }
            else if (mid < x / mid)
            {
                lo = mid + 1;
            }
            else if (mid > x / mid)
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
};