import math
def lcm2(a,b,c):
    return (a*lcm(b,c))//math.gcd(a,lcm(b,c))

def lcm(a,b):
    return (a*b)//math.gcd(a,b)

def check(n,a,b,c,m):
    num=0
    
    num=m//a + m//b + m//c - m//lcm(a,b) - m//lcm(b,c) - m//lcm(a,c) + m//lcm2(a,b,c)
    
    return num>=n


class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        l=min(a,b,c)-1
        r=n*min(a,b,c)
        
        while(r-l>1):
            m=l+(r-l)//2
            
            if(check(n,a,b,c,m)):
                r=m
            else:
                l=m;
        return r
                
                