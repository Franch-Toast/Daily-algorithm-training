/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include "vector"

using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<vector<int>> &graph,int node)
    {
        if (node == graph.size() - 1)
        {
            ans.push_back(path);
            return;
        }
        for(int des:graph[node])
        {
            path.push_back(des);
            dfs(graph,des);
            path.pop_back();
        }
        return;

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0);
        dfs(graph,0);

        return ans;

    }
};
// @lc code=end
