//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/

#define vt vector
#define all(v) v.begin(),v.end()

class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int l=*max_element(all(w)) -1;
        int r=accumulate(all(w),0);
        
        while(r-l>1)
        {
            int m=l+(r-l)/2;
            if(check(w,d,m))
                r=m;
            else
                l=m;
        }
        return r;
        
    }
    
    bool check(vt<int>&w,int d,int m)
    {
        d--;
        int s=0;
        for (auto i:w)
        {
            s+=i;
            if(s>m)
            {
                s=i;
                d--;
            }
        }
        
        return d>=0;
        
        
        
        
    }
    
    
};