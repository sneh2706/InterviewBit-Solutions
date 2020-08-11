/*

Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

*/

int Solution::maxArea(vector<int> &v) {
    int n = v.size();
    int i=0, j=n-1;
    
    int res = 0;
    while(i<j) {
        res = max(res, min(v[i],v[j])*(j-i));
        if(v[i]<v[j])
        i++;
        else
        j--;
    }
    return res;
}
