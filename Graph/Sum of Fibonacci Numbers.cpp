/*

How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

*/

int Solution::fibsum(int n) {
    if(n<1) return 0;
    vector<int> v;
    int a=0, b=1;
    
    v.push_back(a);
    v.push_back(b);
    
    while(a+b<=n) {
        int c=a+b;
        v.push_back(c);
        a=b;
        b=c;
    }
    
    int res=0;
    for(int i=v.size()-1; i>=0; --i) {
        if(v[i]<=n) {
            res++;
            n = n-v[i];
        }
        
        if(n==0) return res;
    }
    return res;
}