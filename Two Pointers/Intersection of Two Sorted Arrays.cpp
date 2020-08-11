/*

Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

*/

int search(const vector<int> &v, int x) {
    int n = v.size(), lo=0, hi=n-1;
    int a = -1, b = -1;
    while(lo<=hi) {
        int mid = lo+(hi-lo)/2;
        if(v[mid]==x) {
            a=mid;
            hi = mid-1;
        }
        else if(v[mid]<x)
        lo = mid+1;
        else
        hi = mid-1;
    }
    
    lo=0, hi=n-1;
    while(lo<=hi) {
        int mid = lo+(hi-lo)/2;
        if(v[mid]==x) {
            b=mid;
            lo=mid+1;
        }
        else if(v[mid]>x)
        hi = mid-1;
        else
        lo = mid+1;
    }
    
    if(a==-1 || b==-1) return 0;
    return abs(b-a)+1;
}

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();
    vector<int> res;
    
    if(m==0 || n==0) return res;
    
    int s = max(A[0],B[0]);
    int e = min(A[m-1],B[n-1]);
    
    map<int,int> umap;
    for(int i=0; i<m; ++i) {
        if(A[i]>=s && A[i]<=e)
        umap[A[i]]++;
    }
    
    for(auto it=umap.begin(); it!=umap.end(); ++it) {
        int nums = search(B,(*it).first);
        nums = min(nums,(*it).second);
        for(int i=0; i<nums; ++i)
        res.push_back((*it).first);
    }
    
    return res;
}
