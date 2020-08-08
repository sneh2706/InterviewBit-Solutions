int Solution::sqrt(int n) 
{
    if(n==1) return 1;
    
    long long int lo=1, hi=n/2;
    while(lo<=hi)
    {
        long long int mid = lo+(hi-lo)/2;
        if(mid*mid==n)
        return mid;
        else if(mid*mid<n && (mid+1)*(mid+1)>n)
        return mid;
        else if(mid*mid<n)
        lo=mid+1;
        else
        hi=mid;
    }
    
    return 0;
}

// Complexity of above solution : Time - O(log n), Space - O(1).
