/*
 * @Author: Franch-Toast
 * @Date: 2024-01-28 09:20:09
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-28 09:38:28
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0) return 0;
        return 1;
    }
};
// @lc code=end
/*
    数学的方法，如果当自己取石头时，剩下的石头的数量是4，则一定会输掉
    因为无论取几个石头，对手会直接取完。
    相应地，每个人的最佳策略就是让对手面临剩下石头是4的倍数，这样对手一定会输
    也就是说，先手的人如果面对的石头不是4的倍数一定会赢
    因为在每一轮不论对手拿几个石头，都可以相应地拿石头使其面临4个石头地窘境
*/

