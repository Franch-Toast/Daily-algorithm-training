/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include "string"
#include "unordered_map"
#include "queue"

using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        /* 哈希表 */
        unordered_map<char,int> cnt;

        for(char ch : s) cnt[ch]++;

        // 再次遍历字符串
        for(int i = 0 ; i < s.size(); i++)
            if(cnt[s[i]] == 1) return i;
        
        // 或者遍历哈希表
        // for(auto aim:cnt)
        // {
        //     if(aim.second == 1) return aim.second;
        // }

        /* 队列 */
        queue<pair<char, int>> q;
        unordered_map<char, int> position;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (!position.count(s[i])) // 第一次出现
            {
                position[s[i]] = i; // 位置
                q.emplace(s[i], i);// 放入队列中
            }
            else
            {
                position[s[i]] = -1; // 第二次出现，把索引位置置为-1

                // 一旦出现字符的重复就把队伍中此前第一次出现的重复的字符弹出
                // 注意 队首的字符一定是排在前面的字符，但是不是一定是重复的
                while (!q.empty() && position[q.front().first] == -1)
                {
                    q.pop();
                }
            }
        }
        return q.empty() ? -1 : q.front().second;

    }
};
// @lc code=end

