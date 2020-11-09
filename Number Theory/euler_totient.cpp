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

int phi(int n)
{
    int result=n;
    for(int i=2;i*i<=n;i++)
    {
        if(result%i==0)
        {
            result = result-result/i;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }

    if(n>1)
        result = result - result/n;
    return result;
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
        int n;
        cin>>n;
        cout<<phi(n)<<endl;

    }

    return 0;
}