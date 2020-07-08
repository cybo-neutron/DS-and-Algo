//Hackerearth Bishu and his girlfriend

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

public:
unordered_map<int,pair<bool,int>> girls;
	graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		for(int i=1;i<=v;i++)
		{
			adjList[i]={};
			girls[i]={false,100000};
		}
		

	}

	void addEdge(int from,int to)
	{
		adjList[from].emplace_back(to);
		adjList[to].emplace_back(from);

	}

	void dfs(int from,int dist)
	{

        
		if(visited.find(from)!=visited.end())
		return;
        cout<<from<<": "<<girls[from].first<<" "<<(girls[from].second>dist)<<" "<<girls[from].second<<" "<<dist<<endl;
        
		visited.insert(from);
		if(girls[from].first)
		{
			if(girls[from].second>dist)
				girls[from].second=dist;
		}

		for(auto i:adjList[from])
		{
			dfs(i,dist+1);
		}


	}

	int findGirl()
	{
		dfs(1,0);
		int g=-1;
		int maxDist=1000000;
		for(auto girl:girls)
		{
			if(girl.second.first)
			{
				if(girl.second.second<maxDist)
					g=girl.first;
				else if(girl.second.second==maxDist)
					g=girl.first<g?girl.first:g;

			}	

		}
		return g;
	}





};

int main()
{
    int v,e;
    cin>>v;
	e=v-1;

    graph g(v,e);
    int from,to;
    for(int i=0;i<e;i++)
    {
        cin>>from>>to;
        g.addEdge(from,to);
    }
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		g.girls[x].first=true;
	}
    for(auto i:g.girls)
    {
        cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
    }

	cout<<g.findGirl();


    return 0;

}