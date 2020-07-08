
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

    unordered_map<int,int> parent;


public:
	graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		for(int i=1;i<=v;i++)
		{
			adjList[i]={};
		}
	}

	void addEdge(int from,int to)
	{
		adjList[from].emplace_back(to);
		adjList[to].emplace_back(from);

	}

    int find_parent(int a)
    {
        if(parent[a]<0)
            return a;
        return parent[a]=find_parent(parent[a]);
    }

    void union_set(int a,int b)
    {
        a=find_parent(a);
        b=find_parent(b);

        if(a!=b)
        {
            parent[a]=parent[a]+parent[b];
            parent[b]=a;
        }

    }

    void make_set()
    {
        for(auto it:adjList)
        {
            for(auto i:it.second)
            {
                union_set(it.first,i);
            }
        }
    }

    int connectedComponents()
    {

        for(auto i:adjList)
        {
            parent[i.first]=-1;
        }
        make_set();

        int count=0;
        for(auto i:parent)
        {
            i.second<0?count++ : count=count;
        }
        return count;


    }


};

int main()
{
    int v,e;
    cin>>v>>e;

    graph g(v,e);
    int from,to;
    for(int i=0;i<e;i++)
    {
        cin>>from>>to;
        g.addEdge(from,to);
    }


    return 0;

}