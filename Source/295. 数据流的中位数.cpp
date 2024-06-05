// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem295.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include "vector"

using namespace std;
class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        int n = nums.size();
        int i = 0;
        for(; i < n; i++)
        {
            if(nums[i] >= num) break;
        }
        // nums[i] >= num
        nums.insert(nums.begin()+i,num);

    }
    
    double findMedian() {
        int n = nums.size();
        double ans = (double)(nums[n/2] + nums[(n-1)/2]) / 2;
        return ans;
    }

    vector<int> nums;
};

// int main()
// {
//     MedianFinder test;
//     test.addNum(6);
//     test.findMedian();
//     test.addNum(10);
//     test.findMedian();
//     test.addNum(2);
//     test.findMedian();
//     return 0;
// }
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

