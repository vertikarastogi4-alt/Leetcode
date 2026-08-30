class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;
        for( char ch : s)
        {
        if(ch == ')') st.pop(); 
            if(!(st.empty())) ans+=ch;
            if( ch=='(') st.push(ch);

        }
        return ans;
    }
};