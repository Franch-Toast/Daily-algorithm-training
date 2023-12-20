// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1053.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // 使用贪心的思想
        int n = arr.size();
        int i = n-2;
        for(;i >= 0; i--)
        {
            if(arr[i] > arr[i+1]) break;// 找到第一个递减的元素
        }
        if(i < 0) return arr;// 没找到递减的元素或数组长度为1，说明已经是最小排列
        for(int j = n-1; j > i;j--)
        {
            if(arr[j] < arr[i])// 找到第一个小于目标元素的这一“类”元素
            {
                while(arr[j] == arr[j-1]) j--;// 找到同种元素中的最前面的一个，确保字典序最大
                swap(arr[j],arr[i]);
                break;
            }
        }
        return arr;
    }
};

// 题目类似于LeetCode Hot100 中的 M 31. 下一个排列

// @lc code=end

