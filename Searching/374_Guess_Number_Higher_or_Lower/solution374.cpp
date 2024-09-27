int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n, mid;
        
        while (true) {
            mid = low + (high - low) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid;
            } else if (res == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
};

// Runtime1: 0ms, beats 100%
// Memory1: 7.40MB, beats 98.44%

// Runtime2: 0ms, beats 100%
// Memory2: 7.67MB, beats 15.49%

// Runtime3: 0ms, beats 100%
// Memory3: 7.59MB, beats 69.62%