/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int num = 0;
        int profit = 0;
        int n = customers.size();
        int cur = 0;

        if (4 * boardingCost - runningCost <= 0) return -1;

        for (int i = 0; i < n; i++)
        {
            cur += customers[i];
            int temp = min(cur, 4) * boardingCost - runningCost;
            if (temp > 0)
            {
                num = i + 1;
                profit += temp;
            }
            cur -= min(cur, 4);
        }

        // if(cur == 0) return num;

        while (1)
        {
            n++;
            int temp = min(cur, 4) * boardingCost - runningCost;
            cur -= min(cur, 4);
            if(temp > 0) 
            {
                num = n;
                profit += temp;
            }
            else break;
        }
        
        if(profit > 0)
            return num;
        else
            return -1;


    }
};
// @lc code=end

