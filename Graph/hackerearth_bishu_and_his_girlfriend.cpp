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
#define inf 1e6

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

    int shortestPath(int vtx,unordered_set<int> vis)
    {
        if(vtx==0)
        {
            return 0;
        }
        if(vis.find(vtx)!=vis.end() )
        {
            return inf;
        }
        vis.insert(vtx);

        int ans=inf;
        for(auto i:adjList[vtx])
        {   
            ans=min(ans, 1+shortestPath(i,vis));
        }

        return ans;
    }

    int pathLength(int vtx)
    {
        unordered_set<int> vis;

        return shortestPath(vtx,vis);

    }



};



int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    int n;
    cin>>n;
    graph g(n,n-1);

    for(int i=0;i<n-1;i++)
    {
        int f,t;
        cin>>f>>t;
        g.addEdge(f-1,t-1);
    }

    int q;
    cin>>q;
    int sPath=inf;
    int sidx=inf;
    for(int i=0;i<q;i++)
    {
        int x;cin>>x;
        int plen=g.pathLength(x-1);
        // cout<<x<<" "<<plen<<endl;
        if(plen==sPath)
        {
            if(x<sidx)
                sidx=x;
        }
        else if(plen < sPath)
        {
            sPath=plen;
            sidx=x;
        }

    }

    cout<<sidx<<endl;
   


    return 0;
}