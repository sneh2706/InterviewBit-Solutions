/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> tmp;
    long m = A.size(), n = B.size();
    
    for(long i=0; i<A.size(); ++i) {
        tmp.push_back(A[i]);
    }
    
    A.resize(m+n);
    long i=0, j=0, k=0;
    while(i<m && j<n) {
        if(tmp[i]<B[j]) {
            A[k] = tmp[i];
            i++;
        }
        else {
            A[k] = B[j];
            j++;
        }
        k++;
    }
    
    while(i<m) {
        A[k] = tmp[i];
        i++;
        k++;
    }
    while(j<n) {
        A[k] = B[j];
        j++;
        k++;
    }
}