// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=30204
 *
 * [922] 按奇偶排序数组 II
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
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        size_t i = 0, j = 1;
        while (i < nums.size() && j < nums.size())
        {
            if (nums[i] % 2 == 0)
            {
                i += 2;
                continue;
            }
            if (nums[j] % 2 == 1)
            {
                j += 2;
                continue;
            }
            if (nums[i] % 2 == 1 && nums[j] % 2 == 0)
            {
                swap(nums[i], nums[j]);
            }
        }

        return std::move(nums);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */
