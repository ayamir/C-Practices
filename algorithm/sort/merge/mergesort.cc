#include <bits/stdc++.h>
#include <vector>

void merge(std::vector<int> &nums, int left, int mid, int right) {
  std::vector<int> tmp(right - left + 1);
  int i = left, j = mid + 1, k = 0;
  while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= right) {
    tmp[k++] = nums[j++];
  }
  for (k = 0; k < tmp.size(); k++) {
    nums[left + k] = tmp[k];
  }
}

void msort(std::vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  msort(nums, left, mid);
  msort(nums, mid + 1, right);
  merge(nums, left, mid, right);
}

void mergesort(std::vector<int> &nums) {
  int n = nums.size();
  msort(nums, 0, n - 1);
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{1, 9, 2, 4, 0, 8, 5, 6, 3, 7};
  mergesort(nums);
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
