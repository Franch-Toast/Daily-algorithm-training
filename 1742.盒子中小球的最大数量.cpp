/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
#include "numeric"
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        // 暴力哈希表法这里不写了，写一个题解中的找规律方法：
        // 末尾为9的箱子的后面一个箱子编号 = 末尾为9的箱子编号 - （9 * [末尾9的个数]）+ 1
        // 最大的箱子的大小应该为 9+9+9+9+9 = 45
        int box[46] = {0};
        int temp_low = lowLimit;
        int temp = 0;
        int ans = 0;
        
        while(temp_low)
        {
            temp += temp_low%10;
            temp_low /= 10;
        }    
        temp--;
        
        for(int i = lowLimit; i <= highLimit; i++)
        {
            if(i % 10 == 9)
            {
                int cnt = 0;// 用于记录有几个9
                int index = i;
                while(index % 10 == 9)
                {
                    cnt++;
                    index /= 10;
                }
                box[++temp]++;
                temp = temp - 9 * cnt;
            }
            else box[++temp]++;
            ans = max(ans,box[temp]);
        }
    
        return ans;
    }
};
// @lc code=end

