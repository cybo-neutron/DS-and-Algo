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



};

class graph_weighted
{

    struct data
    {
        int v,d;
    };
    
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

    void dijkstra()
    {
        auto comp=[](data a,data b)
        {
            return a.d>b.d;
        };
        priority_queue<data,vector<data>,decltype(comp)> pq(comp);
        unordered_map<int,int> dist;
        const int inf=1000000;
        for(int i=1;i<=v;i++)
        {
            dist[i]=inf;
        }
        dist[1]=0;
        pq.push({1,dist[1]});
        unordered_set<int> vis;
        while(!pq.empty())
        {
            int x=pq.top().v;
            
            pq.pop();
            for(auto i:adjList[x])
            {
                if(dist[x] + i.second < dist[i.first] )
                {
                    dist[i.first]=dist[x]+i.second;
                    pq.push({i.first,dist[i.first]});
                }
            }

        }

        for(int i=1;i<=v;i++)
        {
            cout<<dist[i]<<" ";
        }        

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
    graph_weighted g(v,e);
    for(int i=0;i<v;i++)
    {
        int f,t,w;
        cin>>f>>t>>w;
        g.addEdge(f,t,w);

    }
    g.dijkstra();

    return 0;
}