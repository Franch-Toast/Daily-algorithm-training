/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
#include "vector"
#include "queue"
#include "numeric"
#include "math.h"

using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int ans = accumulate(piles.begin(),piles.end(),0);
        for(int pile:piles)
            q.push(pile);
        while(k--)
        {
            int temp = q.top();
            q.pop();
            ans -= floor(temp/2);
            q.push(temp - floor(temp/2));
        }
    
        return ans;
    }
};
// @lc code=end

