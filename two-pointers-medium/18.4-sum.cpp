// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 4Sum
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdalign>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> isum(vector<int> &nums, auto i, auto j,
                           long long int target, int x) {
    assert(x >= 2);
    vector<vector<int>> res;
    if (x > 2) {
      for (auto l = i; l < j - x + 2; l++) {
        vector<vector<int>> vec = isum(nums, l + 1, j, target - *l, x - 1);
        if (!vec.empty()) {
          for_each(vec.begin(), vec.end(), [&](auto &i) { i.push_back(*l); });
          res.insert(res.end(), vec.begin(), vec.end());
          while (l < j - x + 2 && *l == *(l + 1)) {
            ++l;
          }
        }
      }
    } else {

      while (i < j) {
        auto sum = *i + *j;
        if (sum == target) {
          res.push_back({*i, *j});
          while (i < j && *i == *(i + 1)) {
            ++i;
          }
          ++i;
          while (i < j && *j == *(j - 1)) {
            --j;
          }
          --j;

        } else {
          sum > target ? j-- : i++;
        }
      }
    }
    return res;
  }
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    auto res = isum(nums, nums.begin(), nums.end() - 1, target, 4);

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,0,-1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
