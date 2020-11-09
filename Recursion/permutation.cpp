//https://leetcode.com/problems/permutations/submissions/

#define vt vector

class Solution {
    vt<vt<int>> col;
    set<int> s;
    vt<int> temp;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        perm(nums);
        temp.reserve(nums.size());
        return col;
    }
    
    void perm(vector<int>&nums)
    {
        if(temp.size()==nums.size())
        {
            col.push_back(temp);
            return;
        }
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
                temp.push_back(nums[i]);
                perm(nums);
                s.erase(nums[i]);
                temp.pop_back();
            }
        }
        
    }
    
};