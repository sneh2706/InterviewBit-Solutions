/*

Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.



*/

int Solution::removeElement(vector<int> &v, int x) {
    int n = v.size();
    if(n==0) return 0;
    if(n==1 && v[0]==x) {
        v.clear();
        return v.size();
    } 
    
    if(n==1) return v.size();
    
    int k=0;
    for(int i=1; i<n; ++i) {
        if(v[k]==x && v[i]!=x) {
            swap(v[i],v[k]);
            k++;
        }
        
        else if(v[k]==x && v[i]==x) continue;
        else k++;
    }
    
    v.erase(v.begin()+k,v.end());
    
    return v.size();
}
