

/*
    1.支付宝消费打折

    众所周知，在一些消费支付的场合中，往往有"支付宝九五折"的优惠。
    这天小盖来到了超市购买物品，一共有n种物品，每种物品只能购买一个，但有的物品支持优惠活动，有的并不支持。
    恰好本超市的结账是有"支付宝九五折"优惠的，小盖的支付宝余额还剩k元，他想知道他仅使用支付宝进行支付的话最多能买几件物品?

输入描述：
输入包含三行。
第一行两个正整数n，k
第二行包含 n个正整数，ai 表示每个物品的价格。
第三行是一个长度为n的只含有0和1的字符串，表示每个物品是否支持优惠。(如果是1代表第i个物品支持优惠，否则不支持。)

输出描述：
输出一个整数，表示最多能购买的物品数量

例子：
    3 975
    1000 500 500
    001
输出
    2
*/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<float> value(n);

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    string support;
    cin >> support;
    for (int i = 0; i < n; i++)
    {
        if (support[i] == '1')
            value[i] = value[i] * 0.95;
    }

    sort(value.begin(), value.end());
    float ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += value[i];
        if (ans > k) // 已经超预算，说明在前面一个索引处就应该停下来
        {
            cout << i; // 注意传的是数量不是索引
            return 0;
        }
    }
    cout << n; // 到最后也没有超过预算
    return 0;
}

/*
    2.小盖切字符串

    小盖定义一个字符串的权值是:字符串辅音数量和元音数量的差的绝对值。
    例如，“arcaea"的权值是 2，因为有4个元音，2 个辅音权值为 4-2 =2。
    现在小盖拿到了一个字符串，她想把这个字符串切成两个非空字符串，需要满足两个字符串的权值相等。
    小盖想知道，有多少种不同的切割方式?
    我们定义，元音有"aeiou"这五种，其余字母均为辅音

输入描述：
    一个仅包含小写字母的字符串，长度不超过200000

输出描述：
    切割方案数

例子：
    arcaea
输出
    2
*/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    string str;
    cin >> str;

    int n = str.length();
    int pres[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        pres[i] += pres[i - 1];
        if (isVowel(str[i - 1]))
        {
            pres[i]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int left = abs(pres[i + 1] - (i + 1 - pres[i + 1]));
        int right = abs(pres[n] - pres[i + 1] - (n - 1 - i - pres[n] + pres[i + 1]));
        if (left == right)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

