// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=30204
 *
 * [10] Regular Expression Matching
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
  bool isMatch(string s, string p) {
    auto ssize = s.size(), psize = p.size();
    vector<vector<int>> dp(ssize + 1, vector<int>(psize + 1, false));
    dp[0][0] = true; // dp[i][j] == true means (s,0,i) match(p,0,j), not
                     // including s[i] and p[j]

    auto match = [&](int i, int j) -> int {
      return (i != -1 && (p[j] == '.' || p[j] == s[i])) ? true : false;
    };

    for (int i = 0; i <= ssize; i++) {
      for (int j = 1; j <= psize; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] |= dp[i][j - 2];
          if (match(i - 1, j - 2)) {
            dp[i][j] |= dp[i - 1][j];
          }
        } else {
          dp[i][j] = match(i - 1, j - 1) && dp[i - 1][j - 1];
        }
      }
    }
    return dp.back().back();
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */
