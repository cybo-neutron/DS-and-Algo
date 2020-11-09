class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        if (n==0)
            return false;
        int m=matrix[0].size();
        int i,j;
        i=0;
        j=m-1;
        while(i<n and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if( target<matrix[i][j])
                j-=1;
            else
                i++;
        }
        return false;
        
    }
};