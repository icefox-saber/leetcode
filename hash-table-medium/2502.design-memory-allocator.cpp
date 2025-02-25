/*
 * @lc app=leetcode.cn id=2502 lang=cpp
 * @lcpr version=30204
 *
 * [2502] Design Memory Allocator
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
class Allocator {
  vector<int> vec;
  int size;

public:
  Allocator(int n) : vec(n, 0), size(n) {}
  int isvalid(int i, int size) {
    if (i + size > this->size) {
      return -1;
    }
    for (int j = i; j < i + size; j++) {
      if (vec[j]) {
        return j;
      }
    }

    return i + size;
  }

  void allocate(int i, int size, int mID) {

    fill(vec.begin() + i, vec.begin() + i + size, mID);
  }

  int allocate(int size, int mID) {
    for (int i = 0; i <= this->size - size; i++) {
      int j = isvalid(i, size);
      if (j == i + size) {
        allocate(i, size, mID);
        return i;
      } else if (j == -1) {
        break;
      } else {
        i = j;
      }
    }
    return -1;
  }

  int freeMemory(int mID) {
    int count = 0;
    for (int i = 0; i < size; i++) {
      if (vec[i] == mID) {
        vec[i] = 0;
        ++count;
      }
    }
    return count;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
// @lc code=end
