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

     bipart(int vtx,vt<int>&bi,int col)
    {
        if(bi[vtx]!=-1)
        {
            return bi[vtx]==col;
        }
        bi[vtx]=col;
        for(auto i:adjList[vtx])
        {
            if(!bipart(i,bi,col^1))
                return false;
        }
        return true;
    }

    bool isbipar(vt<int>&bi)
    {
        for(int i=0;i<v;i++)
        {
            if(bi[i]==-1)
            {
                if(!bipart(i,bi,0))
                    return false;
            }
        }

        return true;
    }



};

class graph_weighted
{
    //in pair first-> vertex and second->weight;
    unordered_map<int,vector<pair<int,int>>> adjList;
    int v,e;
    unordered_map<int,int> parent;

public:
    graph_weighted(int v,int e)
    {
        this->v=v;
        this->e=e;
        for(int i=0;i<v;i++)
        {
            adjList[i]={};
        }

    }

    void addEdge(int from,int to,int weight)
    {
        adjList[from].emplace_back(make_pair(to,weight));
        adjList[to].emplace_back(make_pair(from,weight));
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

    vt<pii> rec(e);
    for(int i=0;i<e;i++)
    {
        int f,t;
        cin>>f>>t;
        g.addEdge(f-1,t-1);
        rec[i]={f-1,t-1};
    }

    vt<int> bi(v,-1);

    if(g.isbipar(bi))
    {
        cout<<"YES"<<endl;
        for(auto i:rec)
        {
            if(bi[i.first]==0 and bi[i.second]==1)
                cout<<0;
            else
                cout<<1;
            
        }
    }
    else{
        cout<<"NO";
    }
    cout<<endl;


    


    return 0;
}