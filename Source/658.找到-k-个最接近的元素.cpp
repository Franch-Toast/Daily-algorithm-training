/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--)
        {
            if (left < 0)
            {
                right++;
            }
            else if (right >= arr.size())
            {
                left--;
            }
            else if (x - arr[left] <= arr[right] - x)
            {
                left--;
            }
            else
            {
                right++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};

              // @lc code=end
