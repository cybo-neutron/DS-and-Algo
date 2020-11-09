//https://leetcode.com/problems/restore-ip-addresses/

class Solution {
    vector<string> col;
public:
    vector<string> restoreIpAddresses(string s) {
        
        helper(s,0,0,"");
        return col;
    }
    
    void helper(string&s,int idx,int count,string temp)
    {
        if(count>4)
            return ;
        if(idx==s.size())
        {
            if(count==4)
            {
                col.push_back(temp);
                return;
            }
        }
        
        for(int i=idx ; i<idx+3;i++)
        {
            if(i>=s.size())
                return;
            string str=s.substr(idx,i-idx+1);
            if(!isvalid(str))
                return ;
            if(temp.length()>0)
            helper(s,i+1,count+1,temp+"."+str);
            else
            helper(s,i+1,count+1,str);
        }
  
    }
    
    bool isvalid(string str)
    {
        if(str.length()==0)
            return false;
        if(str[0]=='0' and str.length()>1)
            return false;
        return stoi(str)>=0 and stoi(str)<=255;
    }
    
};