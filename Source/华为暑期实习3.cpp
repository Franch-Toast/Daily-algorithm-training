

/*
    1.满二叉搜索树查找

    给定2^n-1个不同的整数(1<=n<=10,n为整数)，构建一棵平衡满二叉搜索树

二叉搜索树定义如下：
1)节点的左子树只包含小于当前节点的数。
2)节点的右子树只包含大于当前节点的数。
3)所有左子树和右子树自身必须也是二叉搜索树。例7个数字1234567构建的满二叉搜索树如下所示

1234567

```
    4
   2 6
 1 3 5 7

```
输入描述：

输入分2行，第一行为2^n-1个未排序的整数，空格分隔，用于构建二叉搜索树，其中1<=n<=10
第二行为待查找的整数。
所有输入整数的取值范围为[-32768，32767]。

输出描述：
搜索的路径和结果 路径从根节点开始,用S表示,查找左树用L表示，查找右树使用R表示，找到后使用Y表示，最终未找到使用N表示。

例子：
    2 1 3 7 5 6 4
    6
输出
    SRY
*/

#include "iostream"
#include "vector"
#include "sstream"
#include "algorithm"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode *CreateTree(vector<int> node, int left, int right)
{
    if(left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(node[mid]);
    root->left = CreateTree(node,left,mid - 1);
    root->right = CreateTree(node,mid+1,right);
    return root;
}

int main()
{

    vector<int> node;
    string str;
    getline(cin, str);
    istringstream ss(str);

    while (getline(ss, str, ' '))
    {
        node.push_back(stoi(str));
        // cout << stoi(str)<<endl;
    }
    // getchar();
    int target;
    cin >> target;
    // cout << target;

    int n = node.size();
    sort(node.begin(), node.end());

    TreeNode *root = CreateTree(node,0,n-1);

    string ans = "S";
    while(root != nullptr)
    {
        if(root->val == target)
        {
            ans += "Y";
            cout << ans;
            return 0;
        }
        else if(root->val < target)
        {
            ans += "R";
            root = root->right;
        }
        else
        {
            ans += "L";
            root = root->left;
        }
    }
    ans += "N";
    cout << ans;
    return 0;
}

/*
    2.足球队员射门能力排序

    球队有n个足球队员参与m次射门训练，每次射门进球用1表示，射失则用0表示，依据如下规则对该n个队员的射门能力做排序
    1、 进球总数更多的队员射门能力更强
    2、 若进球总数一样多，则比较最多次连续进球的个数，最多的队员能力更强
    3、 若最多一次连续进球的个数一样多，则比较第一次射失的先后顺序，其中后射失的队员更强，
        若第一次射失顺序相同，则按继续比较第二次射失的顺序，后丢球的队员能术更强，依次类推
    4、 若前3个规则排序后还能力相等，则队员编号更小的能力更强

输入描述：
    第1行，足球队员数n，射门训练次数m。(队员编号从1开始，依次递增)第2行，
    第1~n个队员从第1到m次训练的进球情况，每个队员进球情况为连续的1和0的组合，不同队员用空格分隔n和m均为正整数。
    0 < n <= 10^3，0 < m <= 10^3

输出描述：
    射门能力从强到弱的队员编号,用空格分隔

例子：
    4 5
    11100 00111 10111 01111
输出
    4 3 1 2
*/

#include "iostream"
#include "vector"
#include "sstream"
#include "algorithm"

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;
    // cout << n << m << endl;
    vector<string> goal(n);
    for (int i = 0; i < n; i++)
    {
        cin >> goal[i];
        // cout << goal[i] << endl;
    }

    vector<int> ans;
    vector<int> goals_num(n);
    vector<int> conductive_num(n);
    vector<vector<int>> fail_pos(n);

    for (int j = 0; j < n; j++)
    {
        string str = goal[j];
        int current_conductive_num = 0; // 当前最大连续进球数
        int max_conductive_num = 0;     // 最大连续进球数
        for (int i = 0; i < m; i++)
        {
            int g = str[i] - '0';

            goals_num[j] += g; // 计算进球总数

            if (g != 0)
            {
                current_conductive_num++;                                             // 当前连续进球数++
                max_conductive_num = max(max_conductive_num, current_conductive_num); // 更新最大的连续进球数
            }
            else
            {
                current_conductive_num = 0; // 当前连续进球数数量清0
                fail_pos[j].push_back(i);   // 存放失球的位置
            }
        }
        conductive_num[j] = max_conductive_num;
        ans.push_back(j); // 先存入序号，后面再进行排序
    }

    // 对sort使用lambda表达式自定义排序
    sort(ans.begin(), ans.end(), [ans,goals_num, conductive_num, fail_pos](int a, int b)->bool
         {
            if (goals_num[a] > goals_num[b])
                return goals_num[a] > goals_num[b];
            else if (goals_num[a] < goals_num[b]) return goals_num[a] < goals_num[b];
            else if (conductive_num[a] > conductive_num[b])
                return conductive_num[a] > conductive_num[b];
            else if (conductive_num[a] < conductive_num[b])
                return conductive_num[a] < conductive_num[b];
            for(int i = 0; i < (int)fail_pos[a].size();i++)
            {
                if (fail_pos[a][i] < fail_pos[b][i])
                    return fail_pos[a][i] > fail_pos[b][i];
                else if (fail_pos[a][i] > fail_pos[b][i])
                    return fail_pos[a][i] < fail_pos[b][i];
            }
            return a < b; });

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}

/*
    3.找到内聚值最大的微服务群组

    开发团队为了调研微服务调用情况,对n个微服务调用数据进行了采集分析
    微服务使用数字0至n-1进行编号，给你一个下标从0开始的数组edges，其中edges[i]表示存在一条从微服务微服务edges[i]的接口调用。
    我们将形成1个环的多个微服务称为微服务群组，一个微服务群组的所有微服务数量为L，能够访问到该微服务群组的微服务数量为V这个微服务群组的内聚值H=L-V
    己知提供的数据中有1个或多个微服务群组，请按照内聚值H的结果从大到小的顺序对所有微服务群组((H相等时，取环中最大的数进行比较)排序，
    输出排在第一的做服务群组，输出时每个微服务群组输出的起始编号为环中最小的数。

输入描述：
    入参分为两行输入:
    第一行为n,表示有n个微服务
    第二行为数组edges,其中edges[i]表示存在一条从微服务i到微服务edges[i]的接口调用，数字以空格分隔。
    输入范围说明:
    n == edges.length
    2 <= n <= 10^5
    0 <= edges[i] <= n-1
    edges[i] != i

输出描述：
    输出排在第一的微服务群组的编号数组，按照环的访问顺序输出，走起始编号为环中最小的数，数字以空格分隔。

例子：
    4
    3 3 0 1
输出
    0 3 2
*/

/*
解题思路：
    拓扑排序+遍历微服务群组。如果一个微服务的入度为 0，说明它是一个微服务群组的起始节点，将其加入队列中。
    注意遍历过程中，每次出队列时，将当前节点的入度减 1，并将当前节点的微服务数量加上其父节点的微服务数量再加 1，
    表示当前节点加上了其父节点所在微服务群组中的微服务数量。
    如果当前节点的入度为0，说明其父节点的微服务群组已经遍历完毕，那么就加入队列。

*/



// 以下是java版本的题解
// import java.util.*;

// public
// class MicroserviceAnalysis
// {

// public
//     static void main(String[] args)
//     {
//         Scanner scanner = new Scanner(System.in);
//         int n = scanner.nextInt(); // number of microservices
//         int[] edges = new int[n];
//         int[] inDegree = new int[n];
//         int[] serviceCount = new int[n];

//         for (int i = 0; i < n; ++i)
//         {
//             edges[i] = scanner.nextInt();
//             inDegree[edges[i]]++;
//         }

//         Queue<Integer> queue = new LinkedList<>();
//         for (int i = 0; i < n; ++i)
//         {
//             if (inDegree[i] == 0)
//             {
//                 queue.add(i);
//             }
//         }

//         while (!queue.isEmpty())
//         {
//             int size = queue.size();
//             while (size-- > 0)
//             {
//                 int current = queue.poll();
//                 inDegree[edges[current]]--;
//                 serviceCount[edges[current]] += serviceCount[current] + 1;
//                 if (inDegree[edges[current]] == 0)
//                 {
//                     queue.add(edges[current]);
//                 }
//             }
//         }

//         List<List<Integer>> groups = new ArrayList<>();
//         List<Integer> cohesionValues = new ArrayList<>();
//         List<Integer> maxNumbers = new ArrayList<>();

//         for (int i = 0; i < n; ++i)
//         {
//             if (inDegree[i] == 0)
//                 continue;
//             int current = i;
//             int cohesion = 0;
//             int maxNumber = i;
//             List<Integer> group = new ArrayList<>();
//             while (inDegree[current] > 0)
//             {
//                 cohesion += serviceCount[current];
//                 group.add(current);
//                 inDegree[current] = 0;
//                 current = edges[current];
//                 maxNumber = Math.max(maxNumber, current);
//             }
//             groups.add(group);
//             maxNumbers.add(maxNumber);
//             cohesionValues.add(group.size() - cohesion);
//         }

//         List<Integer> indices = new ArrayList<>();
//         for (int i = 0; i < cohesionValues.size(); ++i)
//         {
//             indices.add(i);
//         }

//         indices.sort(new Comparator<Integer>() {
//             @Override public int compare(Integer a, Integer b)
//             {
//                 if (cohesionValues.get(a).equals(cohesionValues.get(b)))
//                 {
//                     return maxNumbers.get(a) > maxNumbers.get(b) ? -1 : 1;
//                 }
//                 return cohesionValues.get(a) > cohesionValues.get(b) ? -1 : 1;
//             }
//         });

//         List<Integer> result = new ArrayList<>();
//         List<Integer> groupToOutput = groups.get(indices.get(0));

//         int start = Collections.min(groupToOutput);
//         for (int i = 0; i < groupToOutput.size(); ++i)
//         {
//             result.add(start);
//             start = edges[start];
//         }

//         for (int i = 0; i < result.size(); ++i)
//         {
//             System.out.print(result.get(i));
//             if (i != result.size() - 1)
//             {
//                 System.out.print(" ");
//             }
//         }
//     }
// }

