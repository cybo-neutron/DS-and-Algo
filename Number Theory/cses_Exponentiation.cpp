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

ll binpow(ll a,ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2==0)
        return binpow((a*a%mod)%mod,b/2);
   
    return (a*binpow((a*a%mod)%mod,b/2)%mod)%mod;
    
    
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
        ll a,b;
        cin>>a>>b;
        cout<<binpow(a,b)<<endl;
    }
    return 0;
}