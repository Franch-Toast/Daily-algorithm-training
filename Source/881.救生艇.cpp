/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;

        sort(people.begin(),people.end());

        int n = people.size();
        int left = 0,right = n-1;
        while(left < right)
        {
            if(people[right] + people[left] <= limit) left++; // 如果最重和最轻的人能坐下一条船，则最轻的人也上船了
            // 无论最重的人和最轻的人是否能坐下一条船，最重的人一定会单独上一艘船，也就是一定要考虑最重的人
            ans++;
            right--;
        }
        // 如果只剩一个人了，那么一个人单独乘船
        if(left == right) return ++ans;
        return ans;

    }
};
// @lc code=end

