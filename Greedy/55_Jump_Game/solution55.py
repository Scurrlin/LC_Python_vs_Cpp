class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1

        for i in range(len(nums) - 2, -1, -1):
            if i + nums[i] >= goal:
                goal = i
        return goal == 0

# Time Complexity:
# Space Complexity:

# Runtime1: 354ms, beats 61.92%
# Memory1: 17.86MB, beats 36.18%