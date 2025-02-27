// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 * @lcpr version=30204
 *
 * [30] Substring with Concatenation of All Words
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
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res;
    int wordnum = words.size(), wordlen = words[0].length();
    for (size_t i = 0; i < wordlen && i + wordnum * wordlen <= s.size(); i++) {
      unordered_map<string, int> table;
      // 初始化窗口和哈希表
      for (size_t j = i; j < i + wordnum * wordlen; j += wordlen) {
        ++table[s.substr(j, wordlen)];
      }
      for (const auto &word : words) {
        if (!--table[word]) {
          table.erase(word);
        }
      }

      for (size_t start = i; start + wordnum * wordlen <= s.size();
           start += wordlen) {
        if (table.empty()) {
          res.push_back(start);
        }

        auto word = s.substr(start + wordnum * wordlen, wordlen);
        if (!++table[word]) {
          table.erase(word);
        }
        word = s.substr(start, wordlen);
        if (!--table[word]) {
          table.erase(word);
        }
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aaaaaaaaaaaaaa"\n["aa","aa"]\n
// @lcpr case=end

// @lcpr case=start
// "wordgoodgoodgoodbestword"\n["word","good","best","good"]\n
// @lcpr case=end

// @lcpr case=start
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// @lcpr case=end

 */
