class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,j = 0;
        string a="";
        while(i < word1.length() && j < word2.length())
        {
            a += word1[i++];
            a += word2[j++];
        }
        while(i<word1.length())
        {
            a += word1[i++];
        }
        while(j<word2.length())
        {
            a += word2[j++];
        }
        return a;
    }
};