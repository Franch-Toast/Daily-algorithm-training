/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
#include "vector"
#include "string"

using namespace std;
class Solution {
public:
    vector<string> which_day =  { "Thursday", "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday"};
    vector<int> month_day = {31,28,31,30,31,30,31,31,30,31,30,31};
    string dayOfTheWeek(int day, int month, int year) {
        long long total_days = 0;

        // 已知1970年12月31日是星期四
        // 计算距离1970年12月31日的天数
        // 由于数据量很小，直接遍历即可
        total_days = (year - 1971) * 365 + (year - 1969) / 4; // 每四年一个闰年
        for(int i = 0; i < month - 1; i++) total_days += month_day[i]; // 计算月份天数
        if((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month > 2)// 判断是否超过了闰月
            return which_day[(total_days + 1 + day) % 7];
        else return which_day[(total_days + day) % 7];
            

    }
};
// @lc code=end

