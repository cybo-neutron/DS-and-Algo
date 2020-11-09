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

bitset<32> br(string s)
{
    bitset<32> b;
    for(auto i:s)
    {
        b.set(i-'a');
    }
    return b;
}


int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    int n;
    cin>>n;
    vector<string> vs;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        vs.EB(s);
    }

    unordered_map<bitset<32>,vt<string>> m;

    for(auto i:vs)
    {
        bitset<32>temp;
        for(auto j:i)
        {
            temp.set(j-'a');
        }
        m[temp].push_back(i);
    }

    vector<vt<string>> ans;
    for(auto item:m)
    {
        vt<string> temp;
        for(auto i:item.second)
        {
           temp.EB(i);
        }
        ans.EB(temp);
    }
    



    return 0;
}