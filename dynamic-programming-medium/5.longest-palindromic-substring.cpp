// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] Longest Palindromic Substring
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
  string longestPalindrome(string s) {
    int n = s.size();

    vector<vector<bool>> dp;
    vector<bool> vec(n, false);

    for (size_t i = 0; i < n; i++) {
      dp.push_back(vec);
    }

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j <= i; j++) {
        dp[i][j] = 1;
      }
    }
    int maxi = 0, maxj = 0, maxlen = 0;
    for (size_t len = 2; len <= n; len++) {
      for (size_t i = 0; i + len <= n; i++) {
        if (dp[i][i + len - 1] = ispalindrome(dp, s, i, i + len - 1)) {
          if (len > maxlen) {
            maxlen = len;
            maxi = i;
            maxj = i + len - 1;
          }
        }
      }
    }
    string res(s.begin() + maxi, s.begin() + maxj + 1);
    return res;
  }

  bool ispalindrome(const vector<vector<bool>> &dp, const string &s, int i,
                    int j) {
    return (s[i] == s[j] && dp[i + 1][j - 1]) ? true : false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
