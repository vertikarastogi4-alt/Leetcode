class Solution {
public:

    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;

        for (int i = 0; i < v.size(); i++) {
            totalH += ceil((double)v[i] / hourly);
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = INT_MIN;

        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        int low = 1;
        int high = maxi;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};