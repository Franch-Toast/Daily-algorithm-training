/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include "string"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "queue"

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> worddict(wordList.begin(),wordList.end());

        if(worddict.count(endWord) == 0) return 0;// 不存在终点

        unordered_map<string,int> wordpath;
        wordpath[beginWord] = 1;

        queue<string> q;
        q.push(beginWord);


        while(!q.empty())
        {
            string cur = q.front();
            q.pop();

            for(int i = 0; i < cur.size(); i++)
            {
                for(int j = 0; j < 26; j++)
                {
                    string newstring = cur;
                    newstring[i] = 'a' + j;
                    if(!worddict.count(newstring)) continue; // 字典中不存在 没有这条路径直接尝试下一条可能的路径
                    if(newstring == endWord) return wordpath[cur] + 1; // 找到目的地了，直接返回
                    if(wordpath[newstring] == 0) // 如果没有访问过，则说明其访问路径为0，那么把其加入队列中对其进行判断
                    {
                        wordpath[newstring] = wordpath[cur] + 1;
                        q.push(newstring);
                    }
                }
            }

        }
        return 0;
    }
};
// @lc code=end

