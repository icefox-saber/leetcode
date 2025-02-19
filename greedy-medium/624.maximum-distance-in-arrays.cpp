/*
 * @lc app=leetcode.cn id=624 lang=cpp
 * @lcpr version=30204
 *
 * [624] Maximum Distance in Arrays
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
  int maxDistance(vector<vector<int>> &arrays) {
    vector mins(0, 0), maxs(0, 0);
    for (auto &array : arrays) {
      mins.push_back(array.front());
      maxs.push_back(array.back());
    }
    auto s = mins.size();
    size_t minindex = 0, maxindex = 0;
    for (size_t i = 0; i < s; i++) {
      minindex = mins[i] < mins[minindex] ? i : minindex;
      maxindex = maxs[i] > maxs[maxindex] ? i : maxindex;
    }
    if (maxindex != minindex) {
      return maxs[maxindex] - mins[minindex];
    }

    int max = maxs[maxindex], min = mins[minindex];
    mins[minindex] = INT_MAX;
    maxs[maxindex] = INT_MIN;
    for (size_t i = 0; i < s; i++) {
      minindex = mins[i] < mins[minindex] ? i : minindex;
      maxindex = maxs[i] > maxs[maxindex] ? i : maxindex;
    }

    return ::max(maxs[maxindex] - min, max - mins[minindex]);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

 */
