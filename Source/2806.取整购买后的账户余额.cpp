/*
 * @lc app=leetcode.cn id=2806 lang=cpp
 *
 * [2806] 取整购买后的账户余额
 */

// @lc code=start
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundedAmount1 = purchaseAmount / 10 * 10;
        int roundedAmount2 = (purchaseAmount + 9) / 10 * 10;

        int roundedAmount;
        if(abs(roundedAmount1 - purchaseAmount) < abs(roundedAmount2 - purchaseAmount)) roundedAmount = roundedAmount1;
        else roundedAmount = roundedAmount2;

        return 100 - roundedAmount;

    }
};
// @lc code=end

