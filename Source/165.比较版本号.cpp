// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem165.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include "string"
#include "vector"
using namespace std;
class Solution
{
public:
    void split_string(vector<string> &revision, string version)
    {   
        int start = 0;
        int end = 0;
        int n = version.size();
        while(end < n)
        {
            while (end < n && version[end] != '.')
                end++;
            while (version[start] == '0')
                start++;
            revision.push_back(version.substr(start,end-start));
            start = ++end;
        }
    }
    int compareVersion(string version1, string version2)
    {
        vector<string> revision1, revision2;

        split_string(revision1, version1);
        split_string(revision2, version2);

        
        for(int i = 0; i < max(revision1.size(),revision2.size()); i++)
        {
            int temp1,temp2; 
            if(i >= revision1.size() || revision1[i] == "") temp1 = 0;
            else
                temp1 = stoi(revision1[i]);
            if (i >= revision2.size() || revision2[i] == "")
                temp2 = 0;
            else
                temp2 = stoi(revision2[i]);

            if(temp1 < temp2) return -1;
            else if (temp1 > temp2) return 1;
        }
        return 0;

    }
};
// @lc code=end
