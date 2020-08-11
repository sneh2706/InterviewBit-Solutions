/*

Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.

*/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> umap;
    for(int i=0; i<A.size(); ++i) umap[A[i]]++;
    
    for(int i=0; i<A.size(); ++i) {
        umap[A[i]]--;
        int x = B+A[i];
        int y = A[i]-B;
        if((umap.find(x)!=umap.end() && umap[x]>0) || (umap.find(y)!=umap.end() && umap[y]>0)) return 1;
        else umap[A[i]]++;
    }
    return 0;
}
