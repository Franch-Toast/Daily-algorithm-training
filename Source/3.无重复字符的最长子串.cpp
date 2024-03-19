// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include "string"
#include "unordered_set"

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if(n == 0) return 0;
        int ans = 0;
        int left = 0, right = 0;
        unordered_set<char> have;
        while(right < n)
        {
            if(have.count(s[right]))
            {
                while(s[left] != s[right]) 
                {
                    have.erase(s[left]);
                    left++;
                }
                left++;
            }
            else{
                have.insert(s[right]);
                ans = max(ans,right - left + 1);
            }
            right++;
        }
        return ans;
    
    }
};
// @lc code=end
