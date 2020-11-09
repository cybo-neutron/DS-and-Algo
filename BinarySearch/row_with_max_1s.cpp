//https://practice.geeksforgeeks.org/problems/row-with-max-1s/0

#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define all(v) v.begin(),v.end()


void input()
{
    int n,m;
    cin>>n>>m;
    vt<vt<int>> a(n,vt<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<a[i][j]<<"|";
    //     }
    //     cout<<endl;
    // }
    
    int maxno=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        // maxno=max({maxno,(upper_bound(all(a[i]),1) - lower_bound(all(a[i]),1)) });
        int x=upper_bound(all(a[i]),1) -lower_bound(all(a[i]),1) ;
        if(x>maxno)
        {
            ans=i;
            maxno=x;
        }
    }
    
    cout<<ans<<endl;
    
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    input();
	}
	return 0;
}