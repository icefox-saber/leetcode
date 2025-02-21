// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2209 lang=cpp
 * @lcpr version=30204
 *
 * [2209] Minimum White Tiles After Covering With Carpets
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
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    vector dp(floor.size(), vector(numCarpets + 1, 0));

    for (size_t i = 0, j = 0; i < floor.size(); i++) {
      if (floor[i] == '1') {
        ++j;
      }
      dp[i][0] = j;
    }

    for (size_t i = carpetLen; i < floor.size(); i++) {
      for (size_t j = 1; j <= numCarpets; j++) {
        dp[i][j] =
            min(dp[i - carpetLen][j - 1], dp[i - 1][j] + (floor[i] == '1'));
      }
    }

    return dp.back().back();
  }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minimumWhiteTiles
// paramTypes= ["string","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "10110101"\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n2\n3\n
// @lcpr case=end

 */
