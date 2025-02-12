/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 * @lcpr version=30204
 *
 * [1760] Minimum Limit of Balls in a Bag
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
  int minimumSize(vector<int> &nums, int maxOperations) {
    auto l = 1, r = *max_element(nums.begin(), nums.end());
    int count;
    while (l < r) {
      count = 0;
      auto mid = (l + r) / 2;
      for (const auto &num : nums) {
        count += (num - 1) / mid;
      }
      if (count > maxOperations) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return r;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,2]\n4\n
// @lcpr case=end

 */
