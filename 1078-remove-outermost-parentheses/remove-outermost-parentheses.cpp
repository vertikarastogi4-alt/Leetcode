class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int cnt=0;
        for( char ch : s)
        {
        if(ch == ')') cnt--;
            if(cnt>0) ans+=ch;
            if( ch=='(') cnt++;

        }
        return ans;
    }
};