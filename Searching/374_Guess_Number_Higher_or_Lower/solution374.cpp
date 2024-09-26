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