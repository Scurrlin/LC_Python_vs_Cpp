#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void merge(vector<int>& arr, int L, int M, int R) {
        vector<int> left(arr.begin() + L, arr.begin() + M + 1);
        vector<int> right(arr.begin() + M + 1, arr.begin() + R + 1);

        int i = L, j = 0, k = 0;

        while (j < left.size() && k < right.size()) {
            if (left[j] <= right[k]) {
                arr[i++] = left[j++];
            } else {
                arr[i++] = right[k++];
            }
        }

        while (j < left.size()) {
            arr[i++] = left[j++];
        }

        while (k < right.size()) {
            arr[i++] = right[k++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
};

// Runtime1: 372ms, beats 40.30%
// Memory1: 178.20MB, beats 31.51%

// Runtime2: 394ms, beats 37.65%
// Memory2: 178.21MB, beats 30.70%

// Runtime3: 359ms, beats 41.30%
// Memory3: 178.50MB, beats 25.85%