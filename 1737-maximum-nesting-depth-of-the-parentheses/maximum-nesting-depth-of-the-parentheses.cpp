class Solution {
public:
    int maxDepth(string s) {
        int ans=0, n=0;
      
        for(auto ch:s)
        {
            if ( ch=='(') 
            {
                n++;
            }
            else if( ch==')')
            {
                n--;
            }
        
            ans=ans<n?n:ans;
        }
        return ans;
    }
};