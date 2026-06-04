class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0,j=0;
        int m = word1.length(); 
        int n = word2.length();
        while( i < m && j < n )
        {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        } 
        while( i < m )
        {
            res.push_back(word1[i++]);
        }
        while( j < n )
        {
            res.push_back(word2[j++]);
        }
        return res;
    }
};