class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        
        def backtrack(remaining, start, combination):
            if remaining == 0:
                result.append(combination[:])
                return
            
            for i in range(start, len(candidates)):
                if candidates[i] > remaining:
                    continue
                
                combination.append(candidates[i])
                backtrack(remaining - candidates[i], i, combination)
                combination.pop()
    
        backtrack(target, 0, [])    
        return result

# Time Complexity:
# Space Complexity:

# Runtime1: 39ms, beats 97.59%
# Memory1: 16.76MB, beats 11.69%
