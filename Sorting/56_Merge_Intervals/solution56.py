class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda pair: pair[0])
        output = [intervals[0]]

        for start, end in intervals:
            lastEnd = output[-1][1]

            if start <= lastEnd:
                output[-1][1] = max(lastEnd, end)
            else:
                output.append([start, end])
        return output

# Time Complexity: O(NlogN)
# Space Complexity: 0(N)

# Runtime1: 118ms, beats 82.41%
# Memory1: 21.23MB, beats 14.47%