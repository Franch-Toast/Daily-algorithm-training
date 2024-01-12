/*
 * @Author: Franch-Toast
 * @Date: 2024-01-12 18:07:38
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-12 18:51:13
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */

// @lc code=start
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> showed;
        for(string str:words1) showed[str]++;
        int ans = 0;
        for(string str:words2)
        {
            if(showed[str] == 1) // 在前一个哈希表中只出现了一次
            {
                ans++;
                showed[str] = -1; // 表明这个数加入结果中
            }
            else if(showed[str] == -1) // 已经加入结果的数再次出现，说明在这个哈希表中出现了多次
            {
                ans--;// 将其从结果中去掉
                showed[str] = 0;// 将其变为 从未出现过 避免多次从结果中去除
            } 
        }
        return ans;
    }
};

/*这个题也可以使用两个哈希表存储，然后从一个哈希表中中再次取出来遍历*/
// @lc code=end

