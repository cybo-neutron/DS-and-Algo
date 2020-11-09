//https://leetcode.com/problems/unique-paths-iii/

#define vt vector

class Solution {
    vt<vt<int>> visited;
    int n;
    int m;
    int vis;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        if(n==0)
            return 0;
        vis=0;
        m=grid[0].size();
        visited.clear();
        visited.resize(n,vt<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                   vis++; 
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    // visited[i][j]=1;
                    return travel(grid,i,j);
                }
            }
        }
        
        return 0;
        
    }
    
    int travel(vt<vt<int>>&g,int i,int j)
    {
        if(i>=n or j>=m or i<0 or j<0)
            return 0;
        if(visited[i][j]==1)
            return 0;
        if(g[i][j]==-1)
            return 0;
        if(g[i][j]==2)
        {
            if(vis==0)
            {
                // for(int i=0;i<n;i++)
                // {
                //     for(int j=0;j<m;j++)
                //     {
                //         cout<<visited[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<endl;
            return 1;
            }
            
            return 0;
            
        }
        visited[i][j]=1;
        if(g[i][j]==0)
            vis--;
        int ans=travel(g,i+1,j) + travel(g,i,j+1) + travel(g,i,j-1) + travel(g,i-1,j);
        
        visited[i][j]=0;
        if(g[i][j]==0)
            vis++;
        return ans;
        
        
        
    
        
    }
};