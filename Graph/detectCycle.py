import collections

class graph:
    
    def __init__(self,v,e):
        self.v=v
        self.e=e
        self.m=defaultdict(list)
        self.visited=defaultdict(lambda: False)
    
    def addEdge(self,f,t):
        self.m[f].append(t)
        self.m[t].append(f)
        
    def dfs(self,v,p):
        self.visited[v]=True
        for i in self.m[v]:
            
            if(self.visited[i]==True and i!=p):
                return True
            if(self.visited[i]==False and  self.dfs(i,v)==True):
                return True
            
        return False
            
for i in range(int(input())):
    v,e=map(int,input().split())
    g=graph(v,e)
    edges=list(map(int,input().split()))
    for i in range(0,len(edges),2):
        f,t=edges[i],edges[i+1]
        g.addEdge(f,t)
    # print(g.m)
    f=0
    for i in range(v):
        if g.visited[i]==False:
            if g.dfs(i,-1):
                print(1)
                f=1
                break
    if f==0:
        print(0)
    
    
