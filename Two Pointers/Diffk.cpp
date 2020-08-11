/*

Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

*/

int Solution::diffPossible(vector<int> &A, int B){
    int n = A.size();
    for(int j=n-1; j>=0; --j) {
        for(int i=0; i<j; ++i) {
            if(A[j]-A[i]==B)
            return 1;
            else if(A[j]-A[i]<B)
            break;
        }
    }
    return 0;
}
