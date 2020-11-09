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

struct comp
{
    size_t operator()(pii const&p)const{
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};


unordered_map<pii,int,comp> dp;

int lcss(string s,string t,int i,int j)
{
    if(i>=s.size() or j>=t.size())
    {
        return 0;
    }
    if(dp.find({i,j})!=dp.end())
        return dp[{i,j}];

    if(s[i]==t[j])
    {
        int k=0;
        while( (i+k < s.size()) and (j+k)<t.size() and s[i+k]==t[j+k] )
        {
            k++;
        }

        dp[{i,j}]= max({k,lcss(s,t,i+1,j),lcss(s,t,i,j+1) });
    }
    else{

    dp[{i,j}]= max(lcss(s,t,i+1,j),lcss(s,t,i,j+1));
    }

    return dp[{i,j}];
}



int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        string s,t;
        cin>>s>>t;
        dp.clear();
        cout<<lcss(s,t,0,0)<<endl;
        
    }

    return 0;
}