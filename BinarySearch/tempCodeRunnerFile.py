#https://www.spoj.com/problems/AGGRCOW/
#aggressive cows

def check(a,m,k):
    l=a[0]
    c=k-1
    for i in range(len(a)):
        if((a[i]-l) >= m):
            c-=1
            l=a[i]
    if c>0:
        return False;
    return True;
    

def findmin(a,k):
    l=float('inf')
    for i in range(1,len(a)):
        l=min(l,a[i]-a[i-1])

    r=a[len(a)-1]-a[0]+1
    # print(r)
    
    while(r-l>1):
        m=(l+r)//2
        if(check(a,m,k)):
            l=m
        else:
            r=m
    return l
    

for _ in range(int(input())):
    n,k=map(int,input().split())
    a=[]
    for i in range(n):
        a.append(int(input()))
    a.sort()
    # print(a)
    print(findmin(a,k))