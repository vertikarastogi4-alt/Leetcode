class Solution:
    def splitArray(self, nums, k):
        low = max(nums)
        high = sum(nums)

        while low <= high:
            mid = (low + high) // 2

            partitions = 1
            current_sum = 0

            for num in nums:
                if current_sum + num <= mid:
                    current_sum += num
                else:
                    partitions += 1
                    current_sum = num

            if partitions > k:
                low = mid + 1
            else:
                high = mid - 1

        return low