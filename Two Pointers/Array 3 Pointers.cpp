/*

You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

*/

int findclose(int a, int b, int x) {
    if(abs(x-a)<abs(x-b))
    return a;
    
    return b;
}
 
int search(const vector<int> &v, int x) {
   
    int n = v.size();
    if(x<=v[0]) return v[0];
    if(x>=v[n-1]) return v[n-1];
  
    int lo=0, hi=n-1;
    int mid;
    
    while(lo<=hi) {
        mid = lo+(hi-lo)/2;
        if(v[mid]==x)
        return v[mid];
        
        if(x<v[mid]) {
            if(mid>0 && x>v[mid-1])
            return findclose(v[mid],v[mid-1],x);
            
            hi = mid-1;
        }
        
        else {
            if(mid+1<n && x<v[mid+1])
            return findclose(v[mid],v[mid+1],x);
            
            lo = mid+1;
        }
    }
    return v[mid];
}
 
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int res = INT_MAX;
    for(int i=0; i<A.size(); ++i) {
        int x1 = search(B,A[i]);
        int x2 = search(C,A[i]);
        int tmp = max(abs(A[i]-x1),max(abs(x1-x2),abs(x2-A[i])));
        res = min(res,tmp);
    }
    
    for(int i=0; i<B.size(); ++i) {
        int x1 = search(C,B[i]);
        int x2 = search(A,B[i]);
        int tmp = max(abs(x2-B[i]),max(abs(x1-B[i]),abs(x2-x1)));
        res = min(res,tmp);
    }
    
    for(int i=0; i<C.size(); ++i) {
        int x1 = search(A,C[i]);
        int x2 = search(B,C[i]);
        int tmp = max(abs(x2-x1),max(abs(C[i]-x2),abs(C[i]-x1)));
        res = min(res,tmp);
    }
    return res;
}