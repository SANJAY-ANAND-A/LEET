class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "";
        for(char a : s) {
            char c = std::tolower(a); 
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                vowel += a;
            }
        }
        int size = vowel.length()-1;
        for(int i = 0 ; i < s.length() ; i++) {
            char c = std::tolower(s[i]); 
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                s[i] = vowel[size--];
            }
        }
        return s;
    }
};
