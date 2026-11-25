class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> sa(n), rk(nums), old(n), tmp(n), cnt(max(m, n) + 1, 0);
        for (int i = 0; i < n; i++) cnt[rk[i]]++;
        for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[rk[i]]] = i;
        for (int k = 1;; k <<= 1) {
            int p = 0;
            for (int i = max(0, n - k); i < n; i++) tmp[p++] = i;
            for (int i = 0; i < n; i++) if (sa[i] >= k) tmp[p++] = sa[i] - k;
            fill(cnt.begin(), cnt.begin() + m, 0);
            for (int i = 0; i < n; i++) cnt[rk[i]]++;
            for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) sa[--cnt[rk[tmp[i]]]] = tmp[i];
            old = rk;
            rk[sa[0]] = 0;
            p = 1;
            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];
                int ra = a + k < n ? old[a + k] : -1;
                int rb = b + k < n ? old[b + k] : -1;
                rk[b] = (old[a] == old[b] && ra == rb) ? p - 1 : p++;
            }
            if (p == n) break;
            m = p;
        }
        vector<int> lcp(n + 1, 0);
        for (int i = 0, h = 0; i < n; i++) {
            if (rk[i] == 0) { h = 0; continue; }
            int j = sa[rk[i] - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) h++;
            lcp[rk[i]] = h;
            if (h > 0) h--;
        }
        int ans = n;
        for (int r = 0; r < n; r++) {
            int mx = max(lcp[r], r + 1 < n ? lcp[r + 1] : 0);
            if (mx + 1 <= n - sa[r]) ans = min(ans, mx + 1);
        }
        return ans;
    }
};