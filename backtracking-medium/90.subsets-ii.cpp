// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30204
 *
 * [90] Subsets II
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

void creat(vector<vector<int>> &sets, const vector<int> &table,
           vector<int> &creatset, int index) {
  while (index < table.size() && !table[index]) {
    index++;
  }
  if (table.size() == index) {
    sets.push_back(creatset);
    return;
  }

  for (size_t i = 0; i <= table[index]; i++) {
    creatset.insert(creatset.end(), i, index - 10);
    creat(sets, table, creatset, index + 1);
    creatset.resize(creatset.size() - i);
  }
};

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> table(21, 0);
    vector<vector<int>> sets;
    vector<int> creatset;
    vector<int> mintable;
    // 去重
    for (int &num : nums) {
      table[num + 10]++;
    }
    creat(sets, table, creatset, 0);
    return sets;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
