// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1278 lang=cpp
 * @lcpr version=30204
 *
 * [1278] Palindrome Partitioning III
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
  int palindromePartition(string s, int k) {
    vector cnt_to_pal(s.size(), vector(s.size(), 0));
    // ini
    for (size_t len = 2; len <= s.size(); len++) {
      for (size_t i = 0; i + len <= s.size(); i++) {
        cnt_to_pal[i][i + len - 1] = s[i] == s[i + len - 1]
                                         ? cnt_to_pal[i + 1][i + len - 2]
                                         : cnt_to_pal[i + 1][i + len - 2] + 1;
      }
    }

    vector cnt_to_parti(s.size(), vector(k + 1, 0)); //?
    for (size_t i = 0; i < s.size(); i++) {
      cnt_to_parti[i][1] = cnt_to_pal[0][i];
    }

    for (size_t i = 1; i < s.size(); i++) {
      for (size_t cnt = 2; cnt <= k; cnt++) // 0?
      {
        int min = numeric_limits<int>::max();
        for (size_t j = cnt - 2; j < i; j++) {
          min = ::min(min, cnt_to_parti[j][cnt - 1] + cnt_to_pal[j + 1][i]);
        }
        cnt_to_parti[i][cnt] = min;
      }
    }

    int res = cnt_to_parti.back().back();

    return res;
  }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=palindromePartition
// paramTypes= ["string","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "abab"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aabbc"\n3\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n8\n
// @lcpr case=end

 */
