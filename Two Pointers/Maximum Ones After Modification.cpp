/*

Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.

*/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int maxm = 0;
    int count = 0;
    
    int i=0, j=0;
    while(j<n) {
        if(A[j]==1) j++;
        else {
            if(count<B) j++,count++;
            else {
                maxm = max(maxm,j-i);
                while(i<=j) {
                    if(A[i]==1) i++;
                    else {
                        i++;
                        count--;
                        break;
                    }
                }
            }
        }
    }
    maxm = max(maxm,j-i);
    return maxm;
}
