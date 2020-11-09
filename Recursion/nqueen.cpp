//https://leetcode.com/problems/n-queens/submissions/
#define fnd(d,x)   d.find(x)==d.end()
#define vt vector
#define pb push_back
class Solution {
    unordered_set<int> rows;
    unordered_set<int> col;
    unordered_set<int> ldi;
    unordered_set<int> rdi;
    vt<vt<string>> sol;
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vt<string> g;
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                s+=".";
            }
            g.pb(s);
        }
        for(auto i:g)
        {
            cout<<i<<" ";
        }
        
    
        solve(g,0,0,n);
        
        return sol;
    }
    
    void solve(vt<string>&g, int i,int j,int n)
    {
        if(j>=n)
            return;
        if(i>=n)
        {
            sol.pb(g);
            return ;
        }
        if(col.find(j)==col.end() and fnd(ldi,i-j) and fnd(rdi,i+j))
        {
            col.insert(j),ldi.insert(i-j),rdi.insert(i+j);
            g[i][j]='Q';
            solve(g,i+1,0,n);
            g[i][j]='.';
            col.erase(j),ldi.erase(i-j),rdi.erase(i+j);
            
        }
        solve(g,i,j+1,n);
        
    }
    
};