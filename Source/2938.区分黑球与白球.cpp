/*
 * @lc app=leetcode.cn id=2938 lang=cpp
 *
 * [2938] 区分黑球与白球
 */

// @lc code=start
#include "string"


using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {

        long long ans = 0;
        long long cnt_1 = 0;
        for(char ch:s)
        {
            if(ch == '1') cnt_1++;
            else
            {
                ans += cnt_1;
            }
        }

        return ans;

    }
};
// @lc code=end

