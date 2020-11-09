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

int wArr(vt<int> input,int n)
{
    unordered_map<int,vector<int>> m;
    for(int i=0;i<n;i++)
    {
      m[input[i]].push_back(i);
    }
    int minNo=INT_MAX;

    for(auto k:m)
    {
        for(int i=1;i<k.second.size();i++)
        {
          minNo=min(minNo, k.second[i]-k.second[i-1] );
        }
    }

  return minNo!=INT_MAX ? minNo +1: 0;
}

int weird_array(int input[],int n)
{
    unordered_map<int,vector<int>> m;
    for(int i=0;i<n;i++)
    {
      m[input[i]].push_back(i);
    }
    int minNo=INT_MAX;

    for(auto k:m)
    {
        for(int i=1;i<k.second.size();i++)
        {
          minNo=min(minNo, k.second[i]-k.second[i-1] );
        }
    }

  return minNo!=INT_MAX ? minNo +1: 0;
}

int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

     int n;cin>>n;
    int v[n];
   for(int i=0;i<n;i++)
   {
     cin>>v[i];
   }

    cout<<weird_array(v,n)<<endl;


    return 0;
}




