class Solution {
public:
        string op = "";
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].size();
        int m = strs.size();
        string str;char c;
        if(m!=0)
        {
             str= strs[0];
        }
        else if(n<=0)
        {
            return "";
        }
        for(int i = 0 ; i < n ; i++)
        {
        for(string s: strs)
        {
            c = s[i];
            if(i>=s.size()||c!=str[i]) return op;
        }
        op += c;
        }
        return op;
        // string op = "";
        // int n = strs.size();
        // if(n==0) return"";
        // string s = strs[0];
        // for(int i = 0 ; i < n ; i++)
        // {
        //     char a = s[i];
        // if(strs[i].find(a)==i && i==n-1)
        // {
        //     op+= strs[0][i];
        // }
        // else if(strs[i].find(a)==-1){
        //     return op;
        // }
        // // else if(strs[i].find(a)!=i){
        // //     return op.substr(0,op.length()-1);
        // // }
        // }
        // return op;
    }
};