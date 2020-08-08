/*

Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
   int row = A.size(), col = A[0].size();
   int mrow = -1;
   for(int i=0; i<row; ++i)
   {
       if(A[i][0]<=B && A[i][col-1]>=B)
       {
           mrow = i;
           break;
       }
   }
   
   if(mrow == -1) return 0;
   int lo=0, hi=col-1;
   while(lo<=hi)
   {
       int mid = lo+(hi-lo)/2;
       if(A[mrow][mid]==B)
       return 1;
       else if(A[mrow][mid]>B)
       hi = mid-1;
       else
       lo = mid+1;
   }
   
   if(A[mrow][lo]==B) return 1;
   return 0;
}

