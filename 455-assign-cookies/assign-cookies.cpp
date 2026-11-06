class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
   sort(g.begin(), g.end());
        sort(s.begin(), s.end());
         int childIndex = 0;
         int cookieIndex = 0;
         int satisfiedChildren = 0;
 
        while (childIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[childIndex]) {
                satisfiedChildren++;
                childIndex++;
                cookieIndex++;
            } else {
                cookieIndex++;
            }
        }
 
        return satisfiedChildren;  
    }
};