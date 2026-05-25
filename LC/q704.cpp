/*

  q704 二分查找 Binary search
  https://leetcode.cn/problems/binary-search/


  示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] < target) {
        // mid 比 target 要小, target 在右边, 让 left 变化
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution *s = new Solution();

  vector<int> nums = {-1, 0, 3, 5, 9, 12};

  cout << s->search(nums, 9) << endl;

  return 0;
}
