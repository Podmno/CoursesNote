#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int calc(int amount, int current_coin, vector<int> &coins) {

    // 边界条件
    // amount 已经达成
    if (amount == 0) {
      return 1;
    }

    if (amount < 0) {
      return 0;
    }

    // 只剩 1 种货币可用
    if (current_coin == 0) {
      int last_decide = amount % coins[0];
      if (last_decide == 0) {
        return 1;
      } else {
        return 0;
      }
    }

    return (calc(amount, current_coin - 1, coins) +
            calc(amount - coins[current_coin], current_coin, coins));
  }

  int change(int amount, vector<int> &coins) {
    // 使用递归写法
    return calc(amount, coins.size() - 1, coins);
  }
};

int main(int argc, char *argv[]) {

  int amount = 5;

  vector<int> coins = {1, 2, 5};

  Solution *s = new Solution();

  cout << s->change(amount, coins);

  return 0;
}
