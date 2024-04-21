/*
题目：
    有n个怪物排成一排，小红每次攻击可以攻击到第一只怪物或者最后一只怪物，每次攻击会让怪物掉一滴血
    如果希望使得剩余存活的怪物血量相同，最少需要攻击多少次？

    输入描述：
    第一行输入一个正整数n，代表怪物数量，n∈[1,10^5]
    第二行输入n个正整数a_i，代表每个怪物的血量，a_i∈[1,10^5]

    测试用例：
    5
    1 2 2 1 2
    输出：4

*/

#include <iostream>
#include "sstream"

#include <numeric>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> monster(n);

    for (int i = 0; i < n; i++)
    {
        cin >> monster[i];
    }
    int start = 0;
    int num;
    int ans = 0;

    // 开始遍历，i 作为结束位置
    for (int i = 1; i <= n; i++) // 注意这里的索引，要给最后一个结点一个机会，不然结果无法更新
    {
        if (i < n && monster[i] == monster[i - 1])
            continue;

        if (start - 1 >= 0 && monster[start - 1] > monster[i - 1]) // 计算start前面一个怪兽血量是否比当前目标血量高
        {
            start--; // 更新start
        }
        if (i < n && monster[i] > monster[i - 1]) // 计算end位置的怪兽血量是否比当前目标血量高
        {
            num = monster[i - 1] * (i - start + 1);
        }
        else
            num = monster[i - 1] * (i - start);

        ans = max(ans, num);
        start = i; // 更新下一个开始位置
    }
    // 获取到了最长的相等的长度
    int origin = accumulate(monster.begin(), monster.end(), 0);

    cout << origin - ans;

    return 0;
}