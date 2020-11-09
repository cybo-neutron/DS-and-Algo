//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/prime-interval/description/
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



//================Seive ==================
vt<bool> isprime(1000001,true);
vt<int> prime;

auto genSeive=[](){

   
    
    isprime[0]=isprime[1]=false;

    for(int i=2;i*i<=1000000;i++)
    {
        if(isprime[i])
        {
           for(int j=i*i;j<=1000000;j+=i)
           {
               isprime[j]=false;
           }
        }
    }



    prime.reserve(100000);
    for(int i=2;i<1000000;i++)
    {
        if(isprime[i])
        {
            prime.EB(i);
        }
    }

    return 0;

}();

/*================== End Seive====================*/





int main()
{
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 
#endif

    

    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        if(isprime[i])
            cout<<i<<" ";
        
    }



    return 0;
}