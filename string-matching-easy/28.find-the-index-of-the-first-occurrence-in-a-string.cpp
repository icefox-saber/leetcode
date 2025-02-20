// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] Find the Index of the First Occurrence in a String
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
// 需要改进成KMP算法
class Solution {
public:
  int strStr(string haystack, string needle) {

    vector next(needle.size(), -1);

    // 计算KMP用的next数组, next[i]表示next[0:next[i]] = next[i - next[i]:i ]
    for (int i = 1, j = 0; i < needle.size(); i++) {
      while (j && needle[j] != needle[i]) {
        j = next[j - 1] + 1;
      }
      if (needle[j] == needle[i]) {
        ++j;
      }
      next[i] = j - 1;
    }

    int n = 0;
    int h = 0;
    while (n < needle.size() && h < haystack.size()) {
      while (n && needle[n] != haystack[h]) {
        n = next[n - 1] + 1;
      }
      if (needle[n] == haystack[h]) {
        n++;
      }
      h++;
    }

    return n == needle.size() ? h - needle.size() : -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "mississippi"\n"issip"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */
