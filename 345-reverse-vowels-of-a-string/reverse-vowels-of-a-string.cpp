class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(char a:s)
        {
            if(a =='a'|| a=='e'|| a=='i' || a=='o' || a=='u'||a =='A'|| a=='E'|| a=='I' || a=='O' || a=='U')
            {
                st.push(a);
            }
        }
        for(int i = 0 ; i < s.length() ; i++)
        {
            char a = s[i];
            if( a=='a'|| a=='e'|| a=='i' || a=='o' || a=='u'||a =='A'|| a=='E'|| a=='I' || a=='O' || a=='U')
            {
                s[i]=st.top();
                st.pop();
            }
            
        }
        return s;
    }
};