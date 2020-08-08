int Solution::pow(int base, int expo, int d) 
{
    if(d==1) return 0;
    long res =1, tmp = base%d;
    
    while(expo>0)
    {
        if(expo&1)
        res = ((res)*tmp)%d;
        
        tmp = (tmp*tmp)%d;
        
        if(tmp<0)
        tmp += d;
        
        expo = expo>>1;
    }
    
    if(res<0)
    return (d-abs(res)%d);
    
    return res%d;
}
