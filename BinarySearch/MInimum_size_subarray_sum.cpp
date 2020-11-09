//minimum size subarray sum
//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/


#define vt vector
#define pb push_back

class Solution {
    vt<int> sarr;
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        sarr.resize(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            sarr[i+1]=nums[i]+sarr[i];
        }
        
        int l=0;
        int r=nums.size();
        
        
        
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(check(sarr,m,s))
                r=m;
            else
                l=m;
        }
        
        if(check(sarr,r,s))
            return r;
        return 0;
    }
    
    bool check(vt<int>&a,int m,int s)
    {
        int n=a.size();
        for(int i=m;i<n;i++)
        {
            if(a[i]-a[i-m] >=s )
                return true;
        }
        return false;
    }
};

