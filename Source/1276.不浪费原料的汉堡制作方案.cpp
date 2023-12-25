/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int total_jumbo = 0;

        if(tomatoSlices == 0 && cheeseSlices == 0) return {0,0};
        // 番茄一定有剩余的情况
        if(tomatoSlices == 0 || cheeseSlices == 0 || tomatoSlices % 2 == 1 || tomatoSlices > cheeseSlices * 4 || tomatoSlices < cheeseSlices) return {};

        tomatoSlices /= 2;
        if(tomatoSlices < cheeseSlices) return {};

        total_jumbo = tomatoSlices - cheeseSlices;
        return {total_jumbo,cheeseSlices-total_jumbo};


    }
};
// @lc code=end

