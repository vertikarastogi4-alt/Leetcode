class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);

        long long mx = 0, total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            total += diff[i];
        }

        long long k = 1LL * k1 + k2;

        if (total <= k) return 0;

        long long left = 0, right = mx;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long need = 0;

            for (int i = 0; i < n; i++) {
                if (diff[i] > mid)
                    need += diff[i] - mid;
            }

            if (need > k)
                left = mid + 1;
            else
                right = mid;
        }

        long long used = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > left) {
                used += diff[i] - left;
                diff[i] = left;
            }
        }

        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == left && left > 0) {
                diff[i]--;
                remaining--;
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
            ans += diff[i] * diff[i];

        return ans;
    }
};
