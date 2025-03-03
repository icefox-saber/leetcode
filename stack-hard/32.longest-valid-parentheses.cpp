/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] Longest Valid Parentheses
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
  int longestValidParentheses(string s) {
    vector vec(s.size(), true);
    vector<int> stk;
    int l = -1;

    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push_back(i);
      } else {
        if (!stk.empty()) {
          l = stk.back();
          stk.pop_back();
          vec[l] = false;
          vec[i] = false;
        } else {
          vec[i] = true;
        }
      }
    }

    size_t res = 0;
    size_t tmp = 0;
    for (size_t i = 0; i < vec.size(); i++) {
      if (!vec[i]) {
        tmp++;
      } else {
        res = max(res, tmp);
        tmp = 0;
      }
    }
    res = max(res, tmp);
    return res;
  }
};

// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
