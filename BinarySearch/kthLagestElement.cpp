//https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#define vt vector
#define all(v) v.begin(),v.end()

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=*min_element(all(nums));
        int r=*max_element(all(nums));
       
        l-=1;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(check(nums,m,k))
                r=m;
            else
                l=m;
        }
        return r;
        
    }
    
    bool check(vt<int>&nums,int m,int k)
    {
        int count=0;
        for(auto i:nums)
        {
            if(i>m)
                k--;
            
        }
        
        if(k>0)
            return true;
        return false;
        
    }
    
};