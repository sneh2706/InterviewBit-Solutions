/*

Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

*/

bool isPossible(int A, int B, vector<int> &C,long long int X){
    int n=C.size();
   long long int t=X;
    int i=0,cnt=1;
    while(i<n){
        if(cnt>A)
         return false;
        if(C[i]>t){
            cnt++;
            t=X;
        }
        else{
            t=t-C[i];
            i++;
        }
    }
    return true;
}
 
int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    long long int sum=0;
    for(int i=0;i<n;i++)
     sum=sum%10000003+C[i]%10000003;
    long long int low=0,high=sum*B;
    long long int ans=high%10000003;
    while(low<=high){
       
        long long int mid=low+(high-low)/2;
        if(isPossible(A,B,C,mid/B)){
         
            ans=mid%10000003;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans%10000003;
}
