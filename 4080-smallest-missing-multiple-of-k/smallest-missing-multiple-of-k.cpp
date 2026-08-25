class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int i=1;i<=200;i++){
            st.insert(i);
        }

        for(int i : nums){
            st.erase(i);
        }
        int t = k;
        while(!st.count(k)){
            k += t;
        }
        return k;
    }
};