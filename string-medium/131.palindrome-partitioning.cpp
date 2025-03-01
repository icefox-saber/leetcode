/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] Palindrome Partitioning
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

  void partition(vector<vector<string>> &res, const vector<vector<bool>> &dp,
                 const string &s, vector<string> &tmp, int i = 0) {
    assert(i <= s.size());
    if (i == s.size()) {
      res.push_back(tmp);
      return;
    }

    for (int len = 1; len + i <= s.size(); len++) {
      if (dp[i][i + len - 1]) {
        tmp.push_back(s.substr(i, len));
        partition(res, dp, s, tmp, i + len);
        tmp.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector dp(s.size(), vector(s.size(), false));
    for (size_t i = 0; i < s.size(); i++) {
      for (size_t j = 0; j <= i; j++) {
        dp[i][j] = true;
      }
    }

    for (size_t len = 2; len <= s.size(); len++) {
      for (size_t i = 0; i + len <= s.size(); i++) {
        dp[i][i + len - 1] =
            s[i] == s[i + len - 1] ? dp[i + 1][i + len - 2] : false;
      }
    }

    vector<vector<string>> res;
    vector<string> tmp{};
    partition(res, dp, s, tmp);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */
