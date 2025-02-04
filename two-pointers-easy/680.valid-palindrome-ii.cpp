/*
 * @lc app=leetcode.cn id=680 lang=cpp
 * @lcpr version=30204
 *
 * [680] Valid Palindrome II
 */


// @lcpr-template-start
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
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
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    for (; i <= j; i++, j--) {
      if (s[i] == s[j]) {
        continue;
      } else // 进去以后出不来
      {

        bool flag = true;
        int tmpi = i + 1;
        int tmpj = j;
        for (; tmpi < tmpj; tmpi++, tmpj--) {
          if (s[tmpi] == s[tmpj]) {
            continue;
          } else {
            flag = false;
            break;
          }
        }
        if (flag == false) {
          int tmpi = i;
          int tmpj = j - 1;
          for (; tmpi < tmpj; tmpi++, tmpj--) {
            if (s[tmpi] == s[tmpj]) {
              continue;
            } else {
              return false;
            }
          }

          return true;
        }

        return true;
      }
    }

    return true;
  }
};
// @lc code=end



/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

