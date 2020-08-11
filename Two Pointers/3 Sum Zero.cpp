/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

*/

vector<vector<int> > Solution::threeSum(vector<int> &v) {
        long n = v.size();
        vector<vector<int>> res;
        
        if(n<=2) return res;
        sort(v.begin(),v.end());
        
        for(long i=0; i<n; ++i) {
            long left = i+1;
            long right = n-1;
            while(left < right && right<n) {
                long tmpsum = (long)v[i] +(long)v[left] + (long)v[right];
                if(tmpsum==0) {
                    vector<int> tmpvec;
                    tmpvec.push_back(v[i]);
                    tmpvec.push_back(v[left]);
                    tmpvec.push_back(v[right]);
                    res.push_back(tmpvec);
                    
                    long leftvalue = v[left];
                    long rightvalue = v[right];
                    while(right<n && left<right && leftvalue==v[left]) ++left;
                    while(right<n && left<right && rightvalue==v[right]) --right;
                }
                
                else if(tmpsum<0) {
                    left++;
                }
                
                else
                --right;
            }
            
            while(i+1<n && v[i]==v[i+1]) ++i;
        }
    return res;
}


