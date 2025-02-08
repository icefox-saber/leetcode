/*
 * @lc app=leetcode.cn id=12 lang=cpp
 * @lcpr version=30204
 *
 * [12] Integer to Roman
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
  string intToRoman(int num) {
    vector<int> vec;
    int times = 1;
    while (num) {
      vec.push_back(num % 10);
      num /= 10;
      times *= 10;
    }
    times /= 10;
    string res;
    int i = vec.size() - 1;
    map<int, char> table;
    table[1] = 'I';
    table[5] = 'V';
    table[10] = 'X';
    table[50] = 'L';
    table[100] = 'C';
    table[500] = 'D';
    table[1000] = 'M';
    while (!vec.empty()) {
      switch (vec.back()) {
      case 4:
        res.push_back(table[1 * times]);
        res.push_back(table[5 * times]);
        times /= 10;
        vec.pop_back();
        break;
      case 9:
        res.push_back(table[1 * times]);
        res.push_back(table[10 * times]);
        times /= 10;
        vec.pop_back();
        break;
      case 0:
        times /= 10;
        vec.pop_back();
        break;
      default:
        if (vec.back() >= 5) {
          res.push_back(table[5 * times]);
          vec.back() -= 5;
        } else {
          res.push_back(table[1 * times]);
          vec.back() -= 1;
        }

        break;
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3749\n
// @lcpr case=end

// @lcpr case=start
// 58\n
// @lcpr case=end

// @lcpr case=start
// 1994\n
// @lcpr case=end

 */
