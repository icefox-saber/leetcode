// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] Permutations II
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
  void creat(vector<int> num, int i, vector<vector<int>> &res) {
    if (i == num.size()) {
      res.push_back(num);
      return;
    }

    for (size_t k = i; k < num.size(); k++) {
      if (k != i && num[i] == num[k]) {
        continue;
      }
      swap(num[i], num[k]);
      creat(num, i + 1, res);
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int>> res;
    creat(num, 0, res);
    return res;
  }
};

// @lc code=end
/*
1
12
21
*/
/*
// @lcpr case=start
// [0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,2]\n
// @lcpr case=end

 */
