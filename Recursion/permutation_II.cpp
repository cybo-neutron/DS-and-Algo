//https://leetcode.com/problems/permutations-ii/

#define vt vector
#define all(v) v.begin(),v.end()

class Solution {
    
  vt<vt<int>> col; 
    vt<int>temp;
    set<int> indx;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(all(nums));
        perm(nums);
        return col;
    }
    
    void perm(vt<int>&nums)
    {
        int n=nums.size();
        if(temp.size()==n)
        {
            col.push_back(temp);
            return ;
        }
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])==s.end() and indx.find(i)==indx.end())
            {
                s.insert(nums[i]);
                temp.push_back(nums[i]);
                indx.insert(i);
                
                perm(nums);
                
                // s.erase(nums[i]);
                temp.pop_back();
                indx.erase(i);
                
            }
            
        }
        
    }
};