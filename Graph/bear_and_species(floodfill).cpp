//https://www.codechef.com/problems/SPECIES

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

struct comp{
    bool operator()(pii const&a) const{
        return hash<int>()(a.first) ^ hash<int>()(a.second);
    }
};

bool impossible;
unordered_set<pii,comp> vis;
int n;
unordered_set<char> animals;
int dfs(int i,int j,vector<vt<char>> g )
{
    vt<int> rv={1,0,-1,0};
    vt<int> cv={0,1,0,-1};
    if(i<0 or i>=n or j<0 or j>=n)
        return 0;
    if(g[i][j]=='.')
        return 0;
    if(vis.find({i,j})!=vis.end())
        return 0;
    vis.insert({i,j});
    if(animals.find('G')!=animals.end() )
    {
        impossible =true;
        return 0;
    }
    int ans=1;
    if(g[i][j]!='?')
    {
        if(g[i][j]=='P' and animals.find('B')!=animals.end())
        {
            impossible=true;
            return 0;
        }
        else if(g[i][j]=='B' and animals.find('P')!=animals.end() )
        {
            impossible=true;
            return 0;  
        }
        animals.insert(g[i][j]);
    }
    

    for(int k=0;k<4;k++)
    {
        ans+=dfs(i+rv[k],j+cv[k],g);
    }

    return ans;


}



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
        int n;
        cin>>n;
        vt<vt<char>> g(n,vt<char>(n,'.'));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>g[i][j];
            }
        }
        vector<int> v;
        impossible=false;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]=='?' and vis.find({i,j})==vis.end())
                {
                    animals.clear();
                    int x=dfs(i,j,g);
                    if(impossible)
                        break;
                    
                    v.EB(x);
                    
                }
            }
        }

        if(impossible)
            cout<<0<<endl;
        else
        {
            int ans=1;
            for(auto i:v)
            {
                ans*=i;
            }
            cout<<ans;
        }
        

        cout<<endl;



    }

    return 0;
}