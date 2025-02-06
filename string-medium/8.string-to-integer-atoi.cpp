// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=30204
 *
 * [8] String to Integer (atoi)
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
  void skipwhitespace(string::iterator &ptr, string &s) {
    while (ptr != s.end() && *ptr == ' ') {
      ptr++;
    }
  }

  int getsign(string::iterator &ptr, string &s) {
    if (ptr == s.end()) {
      return 1; // any num
    }

    switch (*ptr) {
    case '-': {
      ptr++;
      return -1;
    }
    case '+': {
      ptr++;
      return 1;
    }
    default:
      return 1;
    }

    return 1;
  }

  int conversion(string::iterator &ptr, string &s, int flag) {
    long int res = 0;
    while (*ptr >= '0' && *ptr <= '9') {
      res *= 10;
      res += *ptr - '0';
      ptr++;
      if (flag * res < INT_MIN)
        return INT_MIN;
      if (flag * res > INT_MAX) {
        return INT_MAX;
      }
    }

    return flag * res;
  }
  int myAtoi(string s) {
    auto ptr = s.begin();
    skipwhitespace(ptr, s);
    int flag = getsign(ptr, s);
    return conversion(ptr, s, flag);
  }
};
// @lc code=end

/*
// @lcpr case=start
// "-91283472332"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */
