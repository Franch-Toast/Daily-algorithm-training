/*
 * @Author: Franch-Toast
 * @Date: 2024-01-21 12:52:35
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-21 13:02:46
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
#include "math.h"

using namespace std;

/*使用遍历的方法，但是要记得及时剪枝，这里剪枝放在了循环判断的位置*/
// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         for(long a = 0 ; a * a <= c; a++)
//         {
//             double b = sqrt(c-a*a);
//             if(b == (int)b) return 1;
//         }
//         return 0;
//     }
// };



/*使用双指针的方法，从前后分别向中间靠，如果两个指针发生交错了，说明下面的遍历会重复，直接结束即可*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0,b = sqrt(c);
        while(a<=b)
        {
            long temp = a * a + b * b;
            if(temp == c) return 1;
            else if (temp < c) a++;
            else b--;
        }
        return 0;
    }
};


// @lc code=end

