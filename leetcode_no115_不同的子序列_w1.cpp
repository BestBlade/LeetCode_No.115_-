/* ------------------------------------------------------------------|
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2：

输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。
(上箭头符号 ^ 表示选取的字母)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
 

提示：

0 <= s.length, t.length <= 1000
s 和 t 由英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	二维dp法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.8 MB, 在所有 C++ 提交中击败了77.70%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int numDistinct(string s, string t) {
    int m = s.size();
    int n = t.size();
    if (m < n) {
        return 0;
    }
    if (m == n) {
        return s == t;
    }
    vector<vector<unsigned>> res(m, vector<unsigned>(n, 0));
    for (int i = m - 1; i >= 0; --i) {
        if (i == m - 1) {
            if (s[i] == t[n - 1]) {
                res[i][n - 1] = 1;
            }
        }
        else {
            res[i][n - 1] = (s[i] == t[n - 1]) ? 1 + res[i + 1][n - 1] : res[i + 1][n - 1];
        }
    }

    for (int i = m - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            if (s[i] == t[j]) {
                res[i][j] = res[i + 1][j] + res[i + 1][j + 1];
            }
            else {
                res[i][j] = res[i + 1][j];
            }
        }
    }
    return res[0][0];
}

int main() {
    string s = "anacondastreetracecar";

    string t = "contra";
    numDistinct(s, t);
}