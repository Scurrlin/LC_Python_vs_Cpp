class Solution:
    def search(self, nums: List[int], target: int) -> int:
        L, R = 0, len(nums) - 1

        while L <= R:
            mid = (L + R) // 2
            if target == nums[mid]:
                return mid

            if nums[L] <= nums[mid]:
                if target > nums[mid] or target < nums[L]:
                    L = mid + 1
                else:
                    R = mid - 1
            else:
                if target < nums[mid] or target > nums[R]:
                    R = mid - 1
                else:
                    L = mid + 1
        return -1

# Time Complexity: O(logN)
# Space Complexity: O(1)

# Runtime1: 43ms, beats 57.45%
# Memory1: 16.83MB, beats 72.42%