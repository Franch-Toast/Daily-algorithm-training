// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem811.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:

    unordered_map<string,int> res_cnt;

    void get_cnt(string str)
    {  
        int n = str.size();
        int i = 0;
        int num = 0;
        // 先获取数字
        while(str[i]!=' ')
        {
            num = num * 10 + str[i] - '0';
            i++;
        }

        // 再获取后面的每一级域名
        string temp;
        for(int j = n - 1;j >= i;j--)
        {
            while((str[j] != '.' && str[j] != ' '))
            {
                temp = str[j] + temp;
                j--;
                
            }
            res_cnt[temp] += num;
            temp = str[j] + temp;
            
        }
        return;
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;

        for(string str:cpdomains) get_cnt(str);

        for(auto [str,cnt]:res_cnt)
        {
            ans.push_back(to_string(cnt)+" "+str);
        }
        return ans;

    }
};
// @lc code=end

