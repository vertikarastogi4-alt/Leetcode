class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {
                cnt++;

                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long total = 1LL * m * k;

        if (total > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

    
