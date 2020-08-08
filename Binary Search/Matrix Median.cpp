int Solution::findMedian(vector<vector<int> > &v) 
{
    int r = v.size();
    int c = v[0].size();
    
    int minm = INT_MAX, maxm = INT_MIN;
    
    for(int i=0; i<r; ++i)
    {
        minm = min(minm,v[i][0]);
        maxm = max(maxm,v[i][c-1]);
    }
    
    int target = (r*c+1)/2;
    
    while(minm < maxm)
    {
        int mid = (maxm+minm)/2;
        int tmp = 0;
        
        for(int i=0; i<r; ++i)
        tmp += upper_bound(v[i].begin(),v[i].end(),mid) - v[i].begin();
            
        if(tmp<target)
        minm = mid+1;
        else
        maxm = mid;
    }
    
    return minm;
}
