//https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
            return -1;
        if(n==1)
            return 0;
        
        int l=0;
        int r=nums.size()-1;
        if(nums[r]>nums[r-1])
            return r;
        if(nums[l]>nums[l+1])
            return l;
        l++;
        r--;
        
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]>nums[m-1] and nums[m]>nums[m+1])
                return m;
            else if(nums[m] <nums[m+1] )
                l=m+1;
            else
                r=m-1;
        }
        
        return -1;
        
        
    }
};