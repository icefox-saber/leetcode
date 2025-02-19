/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 * @lcpr version=30204
 *
 * [2080] Range Frequency Queries
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
class RangeFreqQuery {
  vector<vector<int>> hashtable_{10001, vector<int>(0, 0)};

public:
  RangeFreqQuery(vector<int> &arr) {
    for (auto &table : hashtable_) {
      table.push_back(INT_MIN);
    }

    auto s = arr.size();
    for (size_t i = 0; i < s; i++) {
      hashtable_[arr[i]].push_back(i);
    }

    for (auto &table : hashtable_) {
      table.push_back(INT_MAX);
    }
  }

  int query(int left, int right, int value) {
    auto &table = hashtable_[value];
    auto searchlindex = [&](int in) {
      int l = 0;
      int s = table.size();
      int r = s - 1;
      int mid = (l + r) / 2;
      while (r > l + 1 && table[mid] != in) {
        table[mid] > in ? r = mid : l = mid;
        mid = (l + r) / 2;
      }

      return table[mid] == in ? mid : mid + 1;
    };
    auto searchrindex = [&](int in) {
      int l = 0;
      int s = table.size();
      int r = s - 1;
      int mid = (l + r) / 2;
      while (r > l + 1 && table[mid] != in) {
        table[mid] > in ? r = mid : l = mid;
        mid = (l + r) / 2;
      }

      return mid;
    };
    int l = searchlindex(left);
    int r = searchrindex(right);
    return r - l + 1;
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end
