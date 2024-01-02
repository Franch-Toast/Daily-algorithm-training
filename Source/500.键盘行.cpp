/*
 * @Author: Franch-Toast
 * @Date: 2024-01-02 11:46:42
 * @email: random996@163.com
 * @github: https://github.com/Franch-Toast
 * @LastEditTime: 2024-01-02 12:05:02
 * @Description: 
 * Shit Code Manufacturing Machine, a low-level bug production expert myself.
 * The code is terrible but can be barely understood. 
 * Welcome to communicate with each other!
 */
/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_set"
using namespace std;

class Solution {
public:
    unordered_set<char> cha1 = {'q','w','e','r','t','y','u','i','o','p',\
                                'Q','W','E','R','T','Y','U','I','O','P'};
    unordered_set<char> cha2 = {'a','s','d','f','g','h','j','k','l',\
                                'A','S','D','F','G','H','J','K','L'};
    unordered_set<char> cha3 = {'z','x','c','v','b','n','m',\
                                'Z','X','C','V','B','N','M'};

    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(string str : words)
        {
            int n = str.size();
            int i = 1;
            if(cha1.count(str[0]))
            {
                while (i < n && cha1.count(str[i])) i++; 
            }
            else if(cha2.count(str[0]))
            {
                while (i < n && cha2.count(str[i])) i++; 
            }
            else{
                while (i < n && cha3.count(str[i])) i++; 
            }
            if(i == n) ans.push_back(str);

        }

        return ans;


    }
};

/*
//下面贴出官方的题解，将“abcd……”转换为对应的行号（0，1，2）,很惊艳
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string rowIdx = "12210111011122000010020202";// 将“abcd……”转换为对应的行号（0，1，2）
        for (auto & word : words) {
            bool isValid = true;
            char idx = rowIdx[tolower(word[0]) - 'a'];// 使用tolower将大写字符转为小写
            for (int i = 1; i < word.size(); ++i) {
                if(rowIdx[tolower(word[i]) - 'a'] != idx) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};

*/


// @lc code=end

