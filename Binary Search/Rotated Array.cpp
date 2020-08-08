/*

Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

*/

int Solution::findMin(const vector<int> &A) {
    int lo=0, hi=A.size()-1;
    int n = A.size();
    
    while(lo<=hi) {
        if(A[lo]<=A[hi]) return A[lo];
        int mid = lo+(hi-lo)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(A[mid]<=A[prev] && A[mid]<=A[next]) return A[mid];
        else if(A[lo]<=A[mid]) lo = mid+1;
        else hi = mid-1;
    }
    return 1;
}