/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start

/* 重点在于每个丑数都可以由其他较小的丑数通过乘以 2 或 3 或 5 得到 */
/*
    但是问题出现在直接计算时可能会出现重复加入队列的情况：
    2（丑数） * 3（因子） = 2（因子） * 3（丑数）
    以上的例子会重复加入 6 ，所以想办法去重：
    给三个指针a、b、c，这三个指针是表示因子2、3、5
    初始时只有一个丑数1，获取新的丑数候选人：
    因子指针（指向不一定是同一个位置） × 对应的自己的因子，获取到三者中最小的那个
    表明是由这个因子指针转向位置的丑数得到的结果，对三个位置进行判断，如果有不同的位置获得到该同样的丑数
    则把位置都++，这是防止重复的方法，因为这个数只要加入一次，后面加入的数一定比这个大。
    也就是说判断的方法不再是对单一的丑数乘三个因子了，而是对不同的丑数乘
    在过程中一定会出现每一个丑数都乘2、3、5的 所以无需担心会漏掉

*/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int a = 0, b = 0, c = 0;
        int res[n];
        res[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int n2 = res[a] * 2, n3 = res[b] * 3, n5 = res[c] * 5;
            res[i] = min(min(n2, n3), n5);
            if (res[i] == n2)
                a++;
            if (res[i] == n3)
                b++;
            if (res[i] == n5)
                c++;
        }
        return res[n - 1];
    }
};

                  // @lc code=end
