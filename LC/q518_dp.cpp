#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    
    // 1. 初始化二维 dp 数组
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // 2. Base Case 1: 凑出金额 0 永远只有 1 种方法
    for (int k = 0; k < n; k++) {
      dp[k][0] = 1;
    }

    // 3. Base Case 2: 只用第 0 种硬币
    for (int i = 0; i <= amount; i++) {
      if (i % coins[0] == 0) {
        dp[0][i] = 1;
      }
    }

    // 4. 正确的双层循环：外层是硬币 (k 从 1 开始)，内层是金额 (i)
    for (int k = 1; k < n; ++k) {
      for (int i = 1; i <= amount; ++i) {
        
        // 默认：不用当前这枚硬币的方法数
        dp[k][i] = dp[k - 1][i];

        // 如果要凑的金额 i 大于等于当前硬币面值，再加上使用这枚硬币的方法数
        if (i - coins[k] >= 0) {
          // 注意这里用的是 dp[k][i - coins[k]]，因为硬币可以无限次使用！
          dp[k][i] = dp[k][i] + dp[k][i - coins[k]];
        }
      }
    }

    return dp[n - 1][amount];
  }
};

int main(int argc, char *argv[]) {

  int amount = 5;

  vector<int> coins = {1, 2, 5};

  Solution *s = new Solution();

  cout << s->change(amount, coins);

  return 0;
}
