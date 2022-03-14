class Solution
{
public:
    void partial_quick_sort(vector<int> &dist, int lo, int hi, int k)
    {
        if (lo >= hi)
            return;

        // cout << lo << " " << hi << endl;

        int i = lo;
        int j = lo;
        int pivot = dist[hi];
        int latest_idx_of_pivot = 0;

        while (j <= hi)
        {
            if (dist[j] >= pivot)
            {
                swap(dist[i], dist[j]);
                latest_idx_of_pivot = i;
                i++;
            }
            j++;
        }

        if (latest_idx_of_pivot < k)
        {
            partial_quick_sort(dist, lo, latest_idx_of_pivot - 1, k);
            partial_quick_sort(dist, latest_idx_of_pivot + 1, hi, k);
        }
        else if (latest_idx_of_pivot > k)
        {
            partial_quick_sort(dist, lo, latest_idx_of_pivot - 1, k);
        }
        else if (latest_idx_of_pivot == k)
        {
            return;
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        partial_quick_sort(nums, 0, nums.size() - 1, k - 1);
        return nums[k - 1];
    }
};


class Solution2 {
public:
    
    int partitionAndGetPivotIndex(vector<int>& nums, int lo, int hi) {
        
        int pivot = nums[hi];
        
        int i = lo; 
        
        for (int j = lo; j <= hi - 1 ; j++) {
            if(nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[i], nums[hi]);
        return i;
        
    }
    
    int quickSelect(vector<int>& nums, int k, int lo, int hi) {
        if(lo == hi) return nums[hi];
        int pivot = partitionAndGetPivotIndex(nums, lo, hi);
        
        if(pivot == k) return nums[k];
        
        if(k < pivot) return quickSelect(nums, k, lo, pivot-1);
        else return quickSelect(nums, k, pivot+1, hi);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int x = quickSelect(nums, k-1, 0, nums.size()-1);
        return x; 
    }
};

