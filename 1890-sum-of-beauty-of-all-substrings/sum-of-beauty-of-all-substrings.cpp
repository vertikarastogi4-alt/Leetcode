class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for( int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mn=INT_MAX , mx=0;
                for( int f: freq ){
                    if(f>0){
                        mn= min(mn,f);
                        mx= max(mx,f);
                    }
                }
                ans+=(mx -mn);
            }
        }
        return ans;
    }
};