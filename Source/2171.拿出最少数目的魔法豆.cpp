/*
 * @Author: Franch-Toast
 * @Date: 2024-01-18 20:24:55
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-18 21:26:25
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start
#include "vector"
#include "numeric"
#include "algorithm"
#include "math.h"
using namespace std;
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(),beans.end());
        long long total = 0,mx = 0;
        
        for(int i = 0; i < beans.size(); i++)
        {
            total += beans[i];
            mx = max(mx , (long long)(n - i) * beans[i]);
        }

        return total - mx;
    }
};
// @lc code=end

/*  
    这里 让我觉得很不错的是，这里枚举没有从1枚举到最大值
    而是针对数组中的每一个豆子的数目进行枚举 ，
    其实可以发现，如果对于中间值（非豆子的数量）进行计算
    得到的面积mx一定有一个比中间值大的豆子数量可以超过它
    所以只需要枚举豆子数量即可。
*/