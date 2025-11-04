#include "parallelMergeSort.hpp"
#include <algorithm>

ParallelMergeSort::ParallelMergeSort(std::vector<int>& nums) : nums(nums) {}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recursiveSort(int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    recursiveSort(left, mid);
    recursiveSort(mid + 1, right);
    merge(left, mid, right);
}

void ParallelMergeSort::merge(int left, int mid, int right) {
    int i = left, j = mid + 1;
    std::vector<int> result;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            result.push_back(nums[i++]);
        else
            result.push_back(nums[j++]);
    }

    while (i <= mid) result.push_back(nums[i++]);
    while (j <= right) result.push_back(nums[j++]);

    for (int k = 0; k < result.size(); ++k)
        nums[left + k] = result[k];
}

void ParallelMergeSort::sort() {
    if (nums.empty()) return;
    recursiveSort(0, nums.size() - 1);
}
