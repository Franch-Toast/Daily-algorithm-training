/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include "string"
#include "vector"

using namespace std;

/* 字典树其实就是 数组迭代 一层一层进行字符迭代，如果字符不存在则该位置为空 */


class Trie // 字典树类
{
private:
    vector<Trie *> children; // 字典树自己有一个26个字母的元素为字典树的容器，作为后续字母字典树
    bool isEnd;              // 判断该位置是否是单词结束的位置

    // 查找prefix的完整字符流字典树是否存在，如果存在，返回最后一个字符的字典树指针，否则返回空指针
    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr) // 如果不存在这个字符，直接返回nullptr
            {
                return nullptr;
            }
            node = node->children[ch]; // 迭代，向下一个字符进行查找
        }
        return node; // 找到了最后一个字符的字典树指针，直接返回即可，在外面判断是否是字符的结束
    }

public:
    // 构造一个字典树
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;   // 获取一个字典树指针，指向自己
        for (char ch : word) // 对word的每一个字符进行遍历
        {
            ch -= 'a';
            if (node->children[ch] == nullptr) // 如果这个字符没有后续了
            {
                node->children[ch] = new Trie(); // 在这个字符处插入新的字典树
            }
            node = node->children[ch]; // 迭代，指针指向这个字符的字典树
        }
        node->isEnd = true; // 所有的字符遍历完了，该字典树的结束标志置1，表明单词结束
    }

    bool search(string word)
    {
        Trie *node = this->searchPrefix(word); // 从字典树查找word
        return node != nullptr && node->isEnd; // 如果最后一个字符返回不是空指针（即存在字典树）同时这个字典树的结束标志置1，说明存在这个word
    }

    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr; // 判断是否存在这个字符流，不需要判断是否在最后字符的位置结束
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
