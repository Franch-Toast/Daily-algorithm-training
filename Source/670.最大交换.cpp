/*
 * @Author: Franch-Toast
 * @Date: 2024-01-22 14:46:17
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-23 09:36:00
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
#include "string"

using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        // 将整型变量转变为字符串变量，方便后面的字符交换swap
        string num_string = to_string(num);
        int n = num_string.size();
        int max_index = n-1;
        int idx1 = -1, idx2 = -1;
        for(int i = n-1; i >= 0; i--)
        {
            if(num_string[i] > num_string[max_index]) max_index = i;
            else if(num_string[i] < num_string[max_index])
            {
                idx1 = i;
                idx2 = max_index;
            }
        }
        if(idx1 >= 0 && idx2 >= 0) swap(num_string[idx1],num_string[idx2]);
        int res = stoi(num_string);
        return res;

    }
};
// @lc code=end


// int main()
// {
//     Solution apple;
//     apple.maximumSwap(2736);
//     return 1;
// }

