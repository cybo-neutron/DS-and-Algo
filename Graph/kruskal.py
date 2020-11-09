
v,e=map(int,input().split())
l=[]
for _ in range(e):
        f,t,w=map(int,input().split())
        l.append((f,t,w))

l.sort(key=lambda x:x[2])

parent={}

for i in range(1,v+1):
        parent[i]=i

def findParent(a):
        if(parent[a]==a):
                return a;
        parent[a]=findParent(parent[a])
        return findParent(parent[a])
        

def unionSet(a,b):
        a=findParent(a)
        b=findParent(b)

        if(a!=b):
                parent[b]=a

s=0
for i in l:
        if findParent(i[0])==findParent(i[1]):
                continue
        s+=i[2]
        unionSet(i[0],i[1])

print(s)


