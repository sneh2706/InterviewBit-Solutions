/*

Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

3 <= N <= 105

1 <= A[i], B <= 108

Given array always contain a bitonic point.

Array A always contain distinct elements.

*/

int find_ind(vector<int> &A, int B, int lo, int hi) {
    if(lo>hi) return -1;
    if(lo==hi) {
        if(A[lo]==B) return lo;
        return -1;
    }
    
    int mid = lo+(hi-lo)/2;
    return max(find_ind(A,B,lo,mid), find_ind(A,B,mid+1,hi));
}
 
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    return find_ind(A,B,0,n-1);
}