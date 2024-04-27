#include <iostream>
#include <utility>
#include <vector>

void shiftDown(std::vector<int> &nums, int n, int i) {
  while (true) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int maxIndex = i;
    if (leftChild < n && nums[leftChild] > nums[maxIndex]) {
      maxIndex = leftChild;
    }
    if (rightChild < n && nums[rightChild] > nums[maxIndex]) {
      maxIndex = rightChild;
    }
    if (maxIndex == i) {
      break;
    }
    std::swap(nums[i], nums[maxIndex]);
    i = maxIndex;
  }
}

void heapsort(std::vector<int> &nums) {
  int n = nums.size();
  // buildHeap
  for (int i = n / 2; i >= 0; i--) {
    shiftDown(nums, n, i);
  }
  // sort
  for (int i = n - 1; i > 0; i--) {
    std::swap(nums[0], nums[i]);
    shiftDown(nums, i, 0);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{1, 9, 2, 4, 0, 8, 5, 6, 3, 7};
  heapsort(nums);
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
