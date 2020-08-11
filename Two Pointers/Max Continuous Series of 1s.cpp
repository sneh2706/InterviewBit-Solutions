/*

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

*/

vector<int> Solution::maxone(vector<int> &v, int k) {
    int n = v.size();
    vector<int> ans;
    
    int zerocount = 0;
    int res = 0,ind1,ind2;
    
    int i=0, j=0;
    while(i<n && j<n) {
        if(v[j]==1)
        j++;
        else {
            if(zerocount==k) {
                if(j-i > res) {
                    res = j-i;
                    ind1 = i;
                    ind2 = j-1;
                }
                
                int k=i;
                while(k<n) {
                    if(v[k]==0)
                    break;
                    
                    k++;
                }
                
                i=k+1;
                zerocount--;
            }
            
            zerocount++;
            j++;
        }
    }
    
    if(res < n-i) {
        res = n-i;
        ind1 = i;
        ind2 = n-1;
    }
    
    for(int i=ind1; i<=ind2; ++i)
    ans.push_back(i);
    return ans;
}