// Will be implementing anohter approaches very soon.

vector<int> Solution::searchRange(const vector<int> &nums, int target) 
{
  vector<int> res;
        int n = nums.size(), low=0, high=n-1, mid;
        
        if(n==0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        while(low<high)
        {
            mid = low+ (high-low)/2;
            if(nums[mid]>=target)
                high = mid;
            else
                low = mid+1;
        }
        
        if(nums[low]==target)
            res.push_back(low);
        else
            res.push_back(-1);
        
        low = 0, high = n-1;
        
        while(low<high)
        {
            mid = low+ (high-low+1)/2;
            if(nums[mid]>target)
                high = mid-1;
            else
                low = mid;
        }
        
        if(nums[low]==target)
            res.push_back(low);
        else
            res.push_back(-1);
        
        return res;
}

// Complexity of above solution - Time:O(log n), Space : O(1).
