//spoj A bug life
// bipartite graph
//https://www.spoj.com/problems/BUGLIFE/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define dbg(x) printf("%d %d\n",#x,x)
#define sci(x) scanf("%d",&x)
#define scd(x) scanf("%lf",&x)
#define scl(x) scanf("%lld",&x)
#define pfi(x) printf("%d",x)
#define pfd(x) printf("%lf",x)
#define pfl(x) printf("%lld",x)




class graph{
	unordered_map<int,vector<int>> adjList;
	int v,e;
  

	
	unordered_set<int> visited;
    unordered_map<int,int>  color;

public:

	graph(int v,int e)
	{
		this->v=v;
		this->e=e;
        for(int i=1;i<=v;i++)
		{
			adjList[i]={};
			color[i]=-1;
		}
		

	}

	void addEdge(int from,int to)
	{
		adjList[from].emplace_back(to);
		adjList[to].emplace_back(from);

	}

    
    
    bool isB()
    {
    
        queue<int> q;
        bool isBa=true;
        for(auto i:adjList)
        {
            if(color[i.first]==-1)
            {
               
                q.push(i.first);
                color[i.first]=0;
                while(!q.empty())
                {
                    int v=q.front();
                    q.pop();
                    for(auto u:adjList[v])
                    {
                        if(color[u]==-1)
                        {
                            color[u]=1^color[v];
                            q.push(u);
                        }
                        else
                        {
                            isBa &=(color[u]!=color[v]);
                        }
                        
                    }
                }
            }
        }
        return isBa;
        
    }



};

int main()
{
    int t;
    cin>>t;
    int testcase=0;
    while(t--)
    {
        testcase++;
        int v,e;
        cin>>v>>e;
        
        graph g(v,e);
        for(int i=0;i<e;i++)
        {
            int f,t;
            cin>>f>>t;
            g.addEdge(f,t);
        }

        printf("Scenario #%d:\n",testcase);
        if(g.isB())
            cout<<"No suspicious bugs found!"<<endl;
        else
            cout<<"Suspicious bugs found!"<<endl;

    }

    
}
