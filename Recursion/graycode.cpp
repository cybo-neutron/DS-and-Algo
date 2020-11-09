
//https://leetcode.com/problems/gray-code/description/
#define pb push_back

class Solution {
    vector<int> col;
    unordered_set<int> done;
public:
    vector<int> grayCode(int n) {
        
        col.pb(0);
        done.insert(0);
        gen(0,n);
        return col;
    }
    
    bool gen(int x,int n)
    {
        if(col.size()==1<<n)
        {
            return true;
        }
        
        for(int i=0;i<n;i++)
        {
            int nm=x^(1<<i);
            if(done.find(nm)==done.end())
            {
                done.insert(nm);
                col.pb(nm);
                if(gen(nm,n))
                    return true;
                col.pop_back();
                done.erase(nm);
            }
        }
        
        return false;
    }
    
    
};