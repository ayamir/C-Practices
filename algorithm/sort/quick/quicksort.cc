#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int partition(std::vector<int> &nums, int left, int right) {
  int mid = left + (right - left) / 2;
  if (nums[left] > nums[mid]) {
    swap(nums[left], nums[mid]);
  }
  if (nums[left] > nums[right]) {
    swap(nums[left], nums[right]);
  }
  if (nums[mid] > nums[right]) {
    swap(nums[mid], nums[right]);
  }
  int pivot = nums[right];
  int i = left, j = right;
  while (i < j) {
    while (i < j && nums[i] <= pivot) {
      i++;
    }
    while (i < j && nums[j] >= pivot) {
      j--;
    }
    swap(nums[i], nums[j]);
  }
  swap(nums[i], nums[right]);
  return i;
}

void qsort(std::vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = partition(nums, left, right);
  qsort(nums, left, pivot - 1);
  qsort(nums, pivot + 1, right);
}

void quicksort(std::vector<int> &nums) {
  int n = nums.size();
  qsort(nums, 0, n - 1);
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{1, 9, 2, 4, 0, 8, 5, 6, 3, 7, 99, 12, 9087, 1024};
  quicksort(nums);
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
