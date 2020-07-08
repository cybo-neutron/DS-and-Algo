//m-ColoringProblem
//https://practice.geeksforgeeks.org/problems/m-coloring-problem/0


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
    int m;

	
	unordered_set<int> visited;
    unordered_map<int,int>  color;

public:

	graph(int v,int e,int m)
	{
		this->v=v;
		this->e=e;
        this->m=m;
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

    bool isSafe(int v,int col)
    {
        for(auto i:adjList[v])
        {
            if(color[i]==col)
            return false;
        }

        return true;

    }

    bool dfs(int v)
    {
        if(v==this->v)
            return true;
        for(int i=1;i<m;i++)
        {
            if(isSafe(v,i))
            {
                color[v]=i;
                if(dfs(v+1))
                    return true;
                color[v]=-1;
            }
        }

        return false;
    }



};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,e;
        cin>>n>>m>>e;
        graph g(n,e,m);
        for(int i=0;i<e;i++)
        {
            int f,t;
            cin>>f>>t;
            g.addEdge(f,t);
        }

        cout<<g.dfs(1)<<endl;

    }

    return 0;

}