// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=680 lang=cpp
 * @lcpr version=30204
 *
 * [680] 验证回文串 II
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        for (; i <= j; i++, j--)
        {
            if (s[i] == s[j])
            {
                continue;
            }
            else // 进去以后出不来
            {

                bool flag = true;
                int tmpi = i + 1;
                int tmpj = j;
                for (; tmpi < tmpj; tmpi++, tmpj--)
                {
                    if (s[tmpi] == s[tmpj])
                    {
                        continue;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    int tmpi = i;
                    int tmpj = j - 1;
                    for (; tmpi < tmpj; tmpi++, tmpj--)
                    {
                        if (s[tmpi] == s[tmpj])
                        {
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                    }

                    return true;
                }

                return true;
            }
        }

        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */
