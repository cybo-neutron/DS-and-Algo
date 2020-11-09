//https://practice.geeksforgeeks.org/problems/word-boggle/0

#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
set<pii> visited;
int n,m;
bool flag=false;
unordered_set<string> printed;
bool search(vt<vt<char>>&grid,string s,int idx,int i,int j)
{
    if(idx>=s.size())
        return true;
    if(i>=n or j>=m or i<0 or j<0)
        return false;
    //already visited
    if(visited.find(mp(i,j))!=visited.end())
    {
        return false;
    }
    
    if(grid[i][j]==s[idx])
    {
        visited.insert(mp(i,j));
        if(search(grid,s,idx+1,i+1,j))
            return true;
        if(search(grid,s,idx+1,i+1,j+1))
            return true;
        if(search(grid,s,idx+1,i+1,j-1))
            return true;
        if(search(grid,s,idx+1,i-1,j))
            return true;
        if(search(grid,s,idx+1,i-1,j-1))
            return true;
        if(search(grid,s,idx+1,i-1,j+1))
            return true;
        if(search(grid,s,idx+1,i,j+1))
            return true;
        if(search(grid,s,idx+1,i,j-1))
            return true;
        visited.erase(mp(i,j));
        
    }
    return false;
    
}

bool searchWord(string s,vt<vt<char>>& grid)
{
    visited.clear();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
            if(search(grid,s,0,i,j))
            {
                printed.insert(s);
                flag=true;
                return true;
            }
        }
    }
    return false;
}



int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    printed.clear();
	    flag=false;
	    int x;
	    cin>>x;
	    vt<string> words;
	    words.reserve(x);
	    for(int i=0;i<x;i++)
	    {
	        string s;
	        cin>>s;
	        words.pb(s);
	    }
	    sort(words.begin(),words.end());
	    cin>>n>>m;
	    
	    vt<vt<char>> grid(n,vt<char>(m));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>grid[i][j];
	        } 
	       
	    }
	    
	    for(int i=0;i<x;i++)
	    {
            
	        if(printed.find(words[i])==printed.end() and searchWord(words[i],grid))
	        {
	            cout<<words[i]<<" ";
	        }
	    }
	    if(!flag)
	    {
	        cout<<-1;
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}