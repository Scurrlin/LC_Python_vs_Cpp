int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n, mid;
        
        while (true) {
            mid = low + (high - low) / 2; // Calculate the mid-point to avoid overflow
            int res = guess(mid);
            
            if (res == 0) {
                return mid; // The guessed number is correct
            } else if (res == -1) {
                high = mid - 1; // The target number is smaller
            } else {
                low = mid + 1; // The target number is larger
            }
        }
    }
};
