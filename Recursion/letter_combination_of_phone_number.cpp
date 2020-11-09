//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    map<int,string> m;
    vector<string> col;
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)
            return col;
        
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        
        helper(digits,"",0);
        return col;
        
    }
    
    
    void helper(string dig,string temp,int n)
    {
        if(n==dig.size())
        {
            col.push_back(temp);
            return ;
        }
        int k=dig[n]-'0';
        for(int i=0;i<m[k].size();i++)
        {
            helper(dig,temp+m[k][i],n+1);
        }
        
    }
    
};