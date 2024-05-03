/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;
class Solution
{
public:
    double average(vector<int> &salary)
    {
        // 方法一
        // sort(salary.begin(),salary.end());
        // return (double)accumulate(salary.begin() + 1, salary.end() - 1,0) / (salary.size() - 2);

        // 方法二
        // int min_money = salary[0], max_money = salary[0];
        // int total = salary[0];
        // for (int i = 1; i < salary.size(); i++)
        // {
        //     total += salary[i];
        //     min_money = min(min_money, salary[i]);
        //     max_money = max(max_money, salary[i]);
        // }
        // return (double)(total - min_money - max_money) / (salary.size() - 2);

        // 方法三
        return (double)(accumulate(salary.begin(), salary.end(), 0) - *min_element(salary.begin(), salary.end()) - *max_element(salary.begin(), salary.end())) / (salary.size() - 2);
    }
};
// @lc code=end
