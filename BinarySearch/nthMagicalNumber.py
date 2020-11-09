def gcd(a,b):
        if b==0:
            return a;
        return gcd(b,a%b)

def lcm(a,b):        
    
    return (a*b)//gcd(a,b);

class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        
        
        def check(m,n,a,b):
            num=m//a + m//b - m//lcm(a,b)
            return num>=n
            
        
        
        l=min(a,b)-1
        r=n*max(a,b)
        
        
        
        while(r-l>1):
            m=l+(r-l)//2
            if(check(m,n,a,b)):
                r=m
            else:
                l=m
        mod=1e9+7
        return int(r%mod)
    
        