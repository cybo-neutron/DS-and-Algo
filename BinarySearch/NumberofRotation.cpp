//Question Link: https://practice.geeksforgeeks.org/problems/rotation/0

#include <bits/stdc++.h>
using namespace std;

int rot(vector<int> v)
{
    int n=v.size();
    int l=0,r=n-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        int next=(m+1)%n;
        int prev=(m-1+n)%n;
        if(v[m]<v[prev])
            return m;
        if(v[m]>=v[0] )
            l=m+1;
        else if(v[m]<=v[n-1])
            r=m-1;

    }

    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto i=0;i<n;i++)
        {
            cin>>v[i];
        }

        cout<<rot(v);

    }
    int t;
    
}