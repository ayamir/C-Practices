#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    int binarySearch(const vector<int> &nums, int target, int base,
                     int length) {
        int res = -1;
        int left = base, right = base + length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                res = mid;
                break;
            }
        }
        return res;
    }

  public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int minIndex = n - 1;
        while (minIndex > 0 && nums[minIndex] > nums[minIndex - 1]) {
            minIndex--;
        }
        if (target > nums[n - 1]) {
            return binarySearch(nums, target, 0, minIndex);
        } else if (target < nums[n - 1]) {
            return binarySearch(nums, target, minIndex, n - 1 - minIndex);
        } else {
            return n - 1;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solu;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solu.search(nums, 7) << endl;
    return 0;
}
