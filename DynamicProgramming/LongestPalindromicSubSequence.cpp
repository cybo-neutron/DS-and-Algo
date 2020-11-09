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

string ans;
struct comp
{
    size_t operator()(pii const& a) const{
        return hash<int>()(a.first) ^ hash<int>()(a.second);
    }
};
unordered_map<pii,int,comp> dp;

int lcs(string s,string temp,int i,int j,string tempans)
{
    if(i>=s.size() or j>=s.size())
    {
        if(tempans.size()>ans.size())
        {
            ans=tempans;
        }
        return 0;
    }

    if(dp.find({i,j}) !=dp.end() )
    {
        return dp[{i,j}];
    }

    if(s[i]==temp[j])
    {
        dp[{i,j}] = max({1+lcs(s,temp,i+1,j+1,tempans+s[i]),lcs(s,temp,i,j+1,tempans),lcs(s,temp,i+1,j,tempans)});
    }
    
    dp[{i,j}] = max({lcs(s,temp,i+1,j,tempans) ,lcs(s,temp,i,j+1,tempans) });
    
    return dp[{i,j}];
}




void solve()
{
    string s;
    cin>>s;
    string temp=s;
    reverse(all(temp));
    ans="";
    dp.clear();
    lcs(s,temp,0,0,"");
    cout<<ans;
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
        solve();
    }

    return 0;
}