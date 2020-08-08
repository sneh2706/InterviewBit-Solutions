bool solve(vector<int> &v, int x, int b)
{
    int i=0, n=v.size(), sum=x, counts=1;
    while(i<n)
    {
        if(sum-v[i]<0)
        {
            counts++;
            sum = x;
        }
        
        else
        i++;
        
        if(counts>b) return false;
    }
    
    return true;
}

int Solution::books(vector<int> &A, int B) 
{
    int sum=0;
    for(int i=0; i<A.size(); ++i)
    sum += A[i];
    
    int lo=0, hi=sum, res=-1;
    while(lo<=hi)
    {
        int mid = lo+(hi-lo)/2;
        if(solve(A,mid,B))
        {
            res = mid;
            hi = mid-1;
        }
        else
        lo = mid+1;
    }
    
    return res;
}
