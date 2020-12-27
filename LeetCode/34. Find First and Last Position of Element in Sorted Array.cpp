class Solution
{
public:
    vector<int> searchRange2(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1, mid;

        int lb = INT_MAX, ub = INT_MIN;
        int found = false;

        // lower bound
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (target > nums[mid])
            {
                lo = mid + 1;
            }
            else if (target < nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                hi = mid - 1;
                lb = min(lb, mid);
                found = true;
            }
        }

        lo = 0;
        hi = nums.size() - 1;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (target > nums[mid])
            {
                lo = mid + 1;
            }
            else if (target < nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
                ub = max(ub, mid);
                found = true;
            }
        }

        // cout << lb << " " << ub << endl;

        if (!found)
            return {-1, -1};
        else
            return {lb, ub};
    }
};