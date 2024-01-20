/*
 * @lc app=leetcode.cn id=2788 lang=cpp
 *
 * [2788] 按分隔符拆分字符串
 */

// @lc code=start
#include "vector"
#include "string"

using namespace std;
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(string str:words)
        {
            int start = 0;
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == separator)
                {
                    if(start == i) 
                    {
                        start++;
                        continue;
                    }
                    ans.push_back(str.substr(start,i-start));
                    start = i+1;
                }
                
            }
            if(start != str.size())
            {
                ans.push_back(str.substr(start,str.size() - start));
            }
        }
        return ans;


    }
};
// @lc code=end

// 也可以使用一个空的字符串str来记录word中两个分隔符中间的内容，逐个添加到str中，再将str添加答案数组中


// 使用分割字符串的方法来做
/*
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (string &word : words) {
            string sub;
            stringstream ss(word);// 转stringstream类才能使用getline函数
            while (getline(ss, sub, separator)) {
                if (!sub.empty()) {
                    cout<<sub<<endl;
                    res.push_back(sub);
                }
            }
        }
        return res;
    }
};

*/