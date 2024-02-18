/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;// 备份一个，防止无法获得原始的字符串
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);// 将原始的字符串放入容器中
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);// 使用迭代器直接将容器放到结果中
        }
        return ans;
    }
};
// @lc code=end

