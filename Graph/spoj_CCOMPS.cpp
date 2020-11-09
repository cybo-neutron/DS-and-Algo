#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define EB emplace_back
#define PB push_back
#define MP make_pair

#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define dbg(x) cout<<#x<<" "<<x
#define sci(x) scanf("%d",&x)
#define scd(x) scanf("%lf",&x)
#define scl(x) scanf("%lld",&x)
#define pfi(x) printf("%d",x)
#define pfd(x) printf("%lf",x)
#define pfl(x) printf("%lld",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vt vector
#define all(v) v.begin(),v.end()

auto fatafat=[](){std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0); return 0;}();

class graph{
    unordered_map<int,vector<int>> adjList;
    int v,e;
public:
    graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        for(int i=0;i<v;i++)
        {
            adjList[i]={};
        }
    }

    void addEdge(int from,int to)
    {
        adjList[from].emplace_back(to);
        adjList[to].emplace_back(from);

    }
     unordered_set<int> vis;

    void dfs(int vtx)
    {
        if(vis.find(vtx)!=vis.end())
            return;

        vis.insert(vtx);

        for(auto i:adjList[vtx])
        {
            dfs(i);
        }

    }

    int connComps()
    {
        vis.clear();
        int count=0;
        for(int i=0;i<v;i++)
        {
            if( vis.find(i)==vis.end())
            {
                dfs(i);
                count++;
            }
        }

        return count;
    }



};


int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    int v,e;
    cin>>v>>e;
    graph g(v,e);
    for(int i=0; i<e;i++)
    {
        int f,t;
        cin>>f>>t;
        g.addEdge(f-1,t-1);
    }

    cout<<g.connComps()<<endl;

    return 0;
}