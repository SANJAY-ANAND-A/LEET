class Solution {
public:
    string reverseWords(string s) {
        std::stringstream stream(s);
        string word;
        std::vector<std::string> words;
        string r="";
        while(stream >> word)
        {
            words.push_back(word);
        }    
        for(int i = words.size()-1; i+1; i--)
        { 
            r += words[i];
            if(i!=0) r+=" ";
        }
        return r;
        }
};