/*

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

*/

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
