/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
#include "string"
#include "unordered_set"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return 0;
        
        vector<int> cnt1(26),cnt2(26); 
        unordered_set<char> cha1,cha2;       

        for(int i = 0;i < word1.size(); i++)
        {
            cnt1[word1[i]-'a']++;
            cha1.insert(word1[i]);
            cnt2[word2[i]-'a']++;
            cha2.insert(word2[i]);
        }
        if(cha1 != cha2) return 0;

        sort(cnt1.begin(),cnt1.end());
        sort(cnt2.begin(),cnt2.end());

        // for(int i = 0; i < 26;i++)
        // {
        //     if(cnt1[i] != cnt2[i]) return 0;
        // }
        // return 1;


        // 直接判断两个容器是否相等即可
        return cnt1 == cnt2;
    }
};
// @lc code=end

