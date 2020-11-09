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
    unordered_map<int,int>parent;

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

    int find_parent(int v)
    {
        if(parent[v]==v)
            return v;
        return parent[v]=find_parent(parent[v]);
    }

    void union_set(int f,int t)
    {
        f=find_parent(f);
        t=find_parent(t);

        if(f!=t)
        {
            parent[t]=f;
        }
    }


    bool feasible(vt<pii>&unequal)
    {
        for(auto item:unequal)
        {
            if(find_parent(item.first) ==find_parent(item.second) )
                return false;
        }
        return true;
    }


};



int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        graph g(v,e);
        vt<pii> unequal;
        for(int i=0;i<e;i++)
        {
            string s;
            getline(cin,s);
            stringstream ss(s);
            cout<<s;
            cin>>ws;



        }
        
        // if(g.feasible(unequal))
        // {
        //     cout<<"YES";
        // }
        // else{
        //     cout<<"NO";
        // }

        // cout<<endl;

    }


    return 0;
}