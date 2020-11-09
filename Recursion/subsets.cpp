//https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> collection;
        vector<int> v;
        v.reserve(n);
        for(int mask=0;mask<(1<<n);mask++)
        {
            int i=0;
            while((1<<i)<=mask)
            {
                if(((1<<i)&mask)!=0)
                {
                      v.emplace_back(nums[i]);
                }

                i++;
            }

            collection.emplace_back(v);
            v.clear();


        }
        return collection;



    }
};