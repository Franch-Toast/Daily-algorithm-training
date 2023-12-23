/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */

// @lc code=start
#include "algorithm"
#include "math.h"
#include "iostream"

using namespace std;
class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;

        if(b < a) swap(a,b);
        cout << __gcd(a,b)<<endl;

        for(int i = 1; i <= sqrt(a); i++)
        {
            cout<< i << endl;
            if(a % i == 0)
            {
                if(b % i == 0)
                    ans++;
                cout<< i << endl;
                if(i != (a/i) && b % (a / i) == 0) ans++;
            }
        }
        return ans;
    }
};
// @lc code=end


/***********
 * 枚举
第一种思路非常简单：从 1 枚举到 min(a,b)小数，判断是否是公因子即可。

class Solution {
public:
    int commonFactors(int a, int b) {
        int ans=1;
        for(int i=2;i<=min(a,b);i++)
        {
            if(a%i==0 && b%i==0) ans++;
        }
         return ans;
    }
};
当然可以更加简化，无需枚举到小数，只需要枚举到sqrt(a 和 b 的最大公因数)即可，同时需要注意的是，由于判断到开方数，所以要判断两个因子，如果有不同的两个因子，则需要ans+=2。

class Solution {
public:
    int commonFactors(int a, int b) {
        int c = gcd(a, b), ans = 0;
        for (int x = 1; x * x <= c; ++x) {//sqrt(a 和 b 的最大公因数)
            if (c % x == 0) {
                ++ans;
                if (x * x != c) {//注意这里，如果两个因子是不同的，则需要加上另一个因子
                    ++ans;
                }
            }
        }
        return ans;
    }
};
通过 gcd(a,b)得到 a 和 b 之间的最大公因数。
 * 
 * 
 * 
 * 
 * 
 * *************/