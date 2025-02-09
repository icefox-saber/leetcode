// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=30204
 *
 * [16] 3Sum Closest
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
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end(), [](int i, int j) { return i < j; });
    auto end = nums.end();
    int res = INT_MAX;
    int diff = INT_MAX;
    int sum = 0;
    int newdiff = 0;
    for (auto i = nums.begin(); i < end - 2; i++) {

      auto l = i + 1, r = end - 1;
      while (l < r) {
        sum = *i + *l + *r;
        newdiff = sum - target;
        if (abs(newdiff) < abs(diff)) {
          res = sum;
          diff = newdiff;
        } else if (newdiff > 0) {
          r--;
        } else if (newdiff < 0) {
          l++;
        } else {
          return target;
        }
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,0,5,-5,3,3,0,-4,-5]\n-2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n3\n
// @lcpr case=end

 */
