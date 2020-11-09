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




int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    int n,k;
    cin>>n>>k;
    vt<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    for(int i=0;i<k;i++)
    {
        int x;cin>>x;
        // auto p=upper_bound(all(v),x);
        // if(*(p-1)==x)
        // {
        //     cout<<p-v.begin();
        // }
        // else{
        //     cout<<p-v.begin();
        // }
        // cout<<endl;
        if(binary_search(all(v),x))
        {
            cout<<lower_bound(all(v),x)-v.begin()+1;
        }
        else
        {
            auto p=lower_bound(all(v),x)-v.begin()+1;
            cout<<p;
        }
        cout<<endl;        
    }


    return 0;
}