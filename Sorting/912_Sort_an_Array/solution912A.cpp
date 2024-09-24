#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    // Function to merge two halves of the array
    void merge(vector<int>& arr, int L, int M, int R) {
        // Create temporary vectors for left and right halves
        vector<int> left(arr.begin() + L, arr.begin() + M + 1);
        vector<int> right(arr.begin() + M + 1, arr.begin() + R + 1);

        int i = L, j = 0, k = 0;

        // Merge the two halves back into the original array
        while (j < left.size() && k < right.size()) {
            if (left[j] <= right[k]) {
                arr[i++] = left[j++];
            } else {
                arr[i++] = right[k++];
            }
        }

        // Copy any remaining elements from the left half
        while (j < left.size()) {
            arr[i++] = left[j++];
        }

        // Copy any remaining elements from the right half
        while (k < right.size()) {
            arr[i++] = right[k++];
        }
    }

    // Recursive function to perform merge sort
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = l + (r - l) / 2;

        // Recursively sort the left and right halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)

// Runtime1: 352ms, beats 37.80%
// Memory1: 178.24MB, beats 30.42%