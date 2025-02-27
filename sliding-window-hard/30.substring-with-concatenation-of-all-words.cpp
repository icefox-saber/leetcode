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
    vector<int> table(s.size(), -1);

    int wsnum = words.size();
    int wslen = words.front().size();
    auto mark = [&](int i) {
      assert(i + wslen <= s.size());
      string tmps(s, i, wslen);
      for (int j = 0; j < wsnum; j++) {

        if (tmps == words[j]) {
          table[i] = j;
          break;
        }
      }
    };
    for (size_t i = 0; i + wslen <= s.size(); i++) {
      mark(i);
    }

    vector<int> tmp(wsnum, 0);
    vector<int> res;
    int num = 0;
    map<string, vector<int>> wordsmap;
    for (size_t i = 0; i < wsnum; i++) {
      wordsmap[words[i]].push_back(i);
    }

    vector wordstable(wsnum, vector(0, 0));

    for (const auto &p : wordsmap) {
      const auto &vec = p.second;
      int b = vec[0];
      wordstable[b].assign(vec.begin(), vec.end());
    }
    auto findfirstzero = [&](int i) {
      for (size_t j = 0; j < wordstable[i].size(); j++) {
        if (tmp[wordstable[i][j]] == 0) {
          return wordstable[i][j];
        }
      }
      return wordstable[i][0];
    };

    auto findfirstbt = [&](int i) {
      for (size_t j = 0; j < wordstable[i].size(); j++) {
        if (tmp[wordstable[i][j]] > 1) {
          return wordstable[i][j];
        }
      }
      for (size_t j = 0; j < wordstable[i].size(); j++) {
        if (tmp[wordstable[i][j]] == 1) {
          return wordstable[i][j];
        }
      }
      assert(false);
      return wordstable[i][0];
    };

    for (int i = 0; i < wslen; i++) {
      fill(tmp.begin(), tmp.end(), 0);

      for (int j = i, size = 0, begin = j, num = 0; j < s.size(); j += wslen) {
        if (table[j] >= 0) {
          int tj = table[j];
          int index = findfirstzero(tj);
          tmp[index]++;

          if (tmp[index] == 1) {
            num++;
          }
        }
        size++;
        if (size > wsnum) {

          if (table[begin] >= 0) {
            int tb = table[begin];
            int index = findfirstbt(tb);
            tmp[index]--;
            if (tmp[index] == 0) {
              num--;
            }
          }

          begin += wslen;
          size--;
        }

        if (num == wsnum) {
          res.push_back(begin);
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
